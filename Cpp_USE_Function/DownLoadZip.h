#include <iostream>
#include <fstream>
#include <filesystem>
#include <curl/curl.h>

// 用于写入文件的回调函数
size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream) {
    std::ofstream* outFile = static_cast<std::ofstream*>(stream);
    outFile->write(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

// 显示下载进度的回调函数
int progress_callback(void* clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    if (dltotal > 0) {
        int progress = static_cast<int>((dlnow * 100) / dltotal);
        std::cout << "\r下载进度: " << progress << "%";
        std::cout.flush();
    }
    return 0;  // 返回 0 表示继续下载
}

// 下载文件的函数
bool downloadFile(const std::string& url, const std::string& outputPath) {
    CURL* curl;
    CURLcode res;
    std::ofstream outFile(outputPath, std::ios::binary);

    if (!outFile.is_open()) {
        std::cerr << "无法打开文件：" << outputPath << std::endl;
        return false;
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outFile);

        // 设置进度回调函数
        curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, progress_callback);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);  // 开启进度显示

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "\n下载失败: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            outFile.close();
            return false;
        }

        curl_easy_cleanup(curl);
    }

    outFile.close();
    std::cout << "\n文件下载完成，保存路径：" << outputPath << std::endl;
    return true;
}

int run_main() {
    std::string url = "https://example.com/path/to/your/file.zip";  // 替换为实际下载链接
    std::string outputPath = "downloaded_file.zip";

    // 检查文件是否已存在
    if (std::filesystem::exists(outputPath)) {
        std::cout << "文件已存在，路径：" << outputPath << "，跳过下载。" << std::endl;
    } else {
        // 文件不存在，执行下载操作
        if (downloadFile(url, outputPath)) {
            std::cout << "下载成功！" << std::endl;
        } else {
            std::cout << "下载失败。" << std::endl;
        }
    }

    return 0;
}