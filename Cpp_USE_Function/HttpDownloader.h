#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <curl/curl.h>


size_t my_write_callback(char* ptr, size_t size, size_t nmemb, void* stream) {
	size_t realsize = size * nmemb;
	std::ofstream* ofs = static_cast<std::ofstream*>(stream);
	ofs->write(ptr, realsize);
	//std::cout << realsize << std::endl;
	return realsize;
}
int my_progress_callback(void* clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
	if (dltotal > 0) {
		int progress = static_cast<int>((dlnow * 100) / dltotal);
		std::cout << "\rDownloading...: " << progress << "%";
		std::cout.flush();
	}
	return 0;  // ���� 0 ��ʾ��������
}
int get_download_length(const std::string& download_url) {
	int download_length = -1;
	CURL* curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, download_url.c_str());
	curl_easy_setopt(curl, CURLOPT_NOBODY, 1);

	// ִ����������
	if (curl_easy_perform(curl) != CURLE_OK) {
		std::cout << "!ERROR: Perform CURL Faild! :( " << std::endl;
		return -1;
	}

	double res = 0; // ������������
	curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &res);
	download_length = (int)res;
	curl_easy_cleanup(curl);// ����curl

	return download_length;
}
int http_download(const std::string& download_url, const std::string& file_path="download_file.tmp") {
	std::ofstream ofs(file_path, std::ios::binary);
	if (!ofs.is_open()) {
		std::cerr << "Can't Open File: " << file_path << std::endl;
		return false;
	}
	// ��ӡ��Ҫ���ص��ļ���С
	int download_size = get_download_length(download_url);
	if (download_size == -1) {
		std::cout << "!ERROR: Get Download_FileSize Faild! :( " << std::endl;
		return false;
	}
	std::cout << "\t--Tip: About to download " << download_size << "B of Data" << std::endl;
	
	// ����CURL����
	CURL* curl = curl_easy_init();
	// ������Ϣ(����·��)
	curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/117.0.0.0 Safari/537.36 Edg/117.0.2045.47");
	curl_easy_setopt(curl, CURLOPT_URL, download_url.c_str());	// ������������
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ofs);	// ����д��������
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write_callback);	//�������ػص�����
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // �����ض���
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60L);       // ���ó�ʱ
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);		// 0L�رյ���ģʽ��1L��������ģʽ
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);		// ����������ʾ
	curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, my_progress_callback);

	// ִ����������
	CURLcode result = curl_easy_perform(curl);

	if (result != CURLE_OK) {
		std::cerr << "!ERROR: Download Fail: " << curl_easy_strerror(result) << "\t:(" << std::endl;
		curl_easy_cleanup(curl);
		ofs.close();
		return false;
	}
	curl_easy_cleanup(curl);
	ofs.close();
	std::cout << std::endl << "\t--Tip: Download Success! :) -Path:  " << file_path << std::endl;
	return true;
}

int main(){
	http_downlaod("download_url", "file_path");
	return 0;
}