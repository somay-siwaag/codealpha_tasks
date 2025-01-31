#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void listFiles(const std::string& path) {
    try {
        if (fs::exists(path) && fs::is_directory(path)) {
            std::cout << "Contents of directory '" << path << "':\n";
            for (const auto& entry : fs::directory_iterator(path)) {
                std::cout << entry.path().filename().string() << "\n";
            }
        } else {
            std::cout << "Path '" << path << "' does not exist or is not a directory.\n";
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void createFile(const std::string& filePath) {
    try {
        std::ofstream file(filePath);
        if (file) {
            std::cout << "File '" << filePath << "' created successfully.\n";
        } else {
            std::cerr << "Failed to create file '" << filePath << "'.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void deleteFile(const std::string& filePath) {
    try {
        if (fs::remove(filePath)) {
            std::cout << "File '" << filePath << "' deleted successfully.\n";
        } else {
            std::cerr << "Failed to delete file '" << filePath << "'.\n";
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void renameFile(const std::string& oldPath, const std::string& newPath) {
    try {
        fs::rename(oldPath, newPath);
        std::cout << "File '" << oldPath << "' renamed to '" << newPath << "' successfully.\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void createDirectory(const std::string& dirPath) {
    try {
        if (fs::create_directory(dirPath)) {
            std::cout << "Directory '" << dirPath << "' created successfully.\n";
        } else {
            std::cerr << "Failed to create directory '" << dirPath << "'.\n";
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void deleteDirectory(const std::string& dirPath) {
    try {
        if (fs::remove_all(dirPath)) {
            std::cout << "Directory '" << dirPath << "' deleted successfully.\n";
        } else {
            std::cerr << "Failed to delete directory '" << dirPath << "'.\n";
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

int main() {
    std::string command;
    std::string path1, path2;

    while (true) {
        std::cout << "\nFile Manager Menu:\n";
        std::cout << "1. List files in a directory\n";
        std::cout << "2. Create a file\n";
        std::cout << "3. Delete a file\n";
        std::cout << "4. Rename a file\n";
        std::cout << "5. Create a directory\n";
        std::cout << "6. Delete a directory\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> command;

        if (command == "1") {
            std::cout << "Enter directory path: ";
            std::cin >> path1;
            listFiles(path1);
        } else if (command == "2") {
            std::cout << "Enter file path: ";
            std::cin >> path1;
            createFile(path1);
        } else if (command == "3") {
            std::cout << "Enter file path: ";
            std::cin >> path1;
            deleteFile(path1);
        } else if (command == "4") {
            std::cout << "Enter current file path: ";
            std::cin >> path1;
            std::cout << "Enter new file path: ";
            std::cin >> path2;
            renameFile(path1, path2);
        } else if (command == "5") {
            std::cout << "Enter directory path: ";
            std::cin >> path1;
            createDirectory(path1);
        } else if (command == "6") {
            std::cout << "Enter directory path: ";
            std::cin >> path1;
            deleteDirectory(path1);
        } else if (command == "7") {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
