#include <iostream>
#include <string>

#include <fstream>
#include <archive.h>
#include <archive_entry.h>
void extractZip(const std::string& filename, const std::string& outputDir) {
    struct archive* a;
    struct archive* ext;
    struct archive_entry* entry;
    int flags = ARCHIVE_EXTRACT_TIME;
    int result;

    // 打开归档文件
    a = archive_read_new();
    archive_read_support_format_zip(a);
    archive_read_support_compression_all(a);

    // 打开输出归档
    ext = archive_write_disk_new();
    archive_write_disk_set_options(ext, flags);
    archive_write_disk_set_standard_lookup(ext);

    // 打开输入文件
    if (archive_read_open_filename(a, filename.c_str(), 10240) != ARCHIVE_OK) {
        std::cerr << "Could not open archive: " << archive_error_string(a) << std::endl;
        return;
    }

    // 解压文件
    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        const char* currentFile = archive_entry_pathname(entry);
        std::string fullOutputPath = outputDir + "/" + currentFile;
        archive_entry_set_pathname(entry, fullOutputPath.c_str());

        std::cout << "Extracting: " << fullOutputPath << std::endl;
        result = archive_write_header(ext, entry);
        if (result == ARCHIVE_OK) {
            const void* buff;
            size_t size;
            la_int64_t offset;

            while (archive_read_data_block(a, &buff, &size, &offset) == ARCHIVE_OK) {
                archive_write_data_block(ext, buff, size, offset);
            }
        } else {
            std::cerr << "Error writing header: " << archive_error_string(ext) << std::endl;
        }
        archive_write_finish_entry(ext);
    }

    // 清理
    archive_read_close(a);
    archive_read_free(a);
    archive_write_close(ext);
    archive_write_free(ext);
}

int run_extractor() {
    std::string zipFile = "jdk.zip";
    std::string outputDir = "./output";

    extractZip(zipFile, outputDir);

    return 0;
}