#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> merged;
    size_t leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] <= right[rightIndex]) {
            merged.push_back(left[leftIndex++]);
        } else {
            merged.push_back(right[rightIndex++]);
        }
    }

    while (leftIndex < left.size()) {
        merged.push_back(left[leftIndex++]);
    }

    while (rightIndex < right.size()) {
        merged.push_back(right[rightIndex++]);
    }

    return merged;
}

std::vector<int> mergeSort(const std::vector<int>& data) {
    if (data.size() <= 1) {
        return data;
    }

    size_t mid = data.size() / 2;
    std::vector<int> left(data.begin(), data.begin() + mid);
    std::vector<int> right(data.begin() + mid, data.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

std::vector<int> readData(const std::string& filename) {
    std::vector<int> data;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        std::getline(file, line); // Skip the first line
        std::getline(file, line);
        std::stringstream ss(line);
        std::string number;

        while (std::getline(ss, number, ';')) {
            data.push_back(std::stoi(number));
        }
    }

    file.close();
    return data;
}

void writeData(const std::string& filename, const std::vector<int>& data) {
    std::ofstream file(filename);

    if (file.is_open()) {
        file << data.size() << std::endl;
        for (size_t i = 0; i < data.size(); ++i) {
            file << data[i];
            if (i < data.size() - 1) {
                file << ";";
            }
        }
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        std::cout << "Usage: " << argv[0] << " <file> [write_output]" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    bool writeOutput = argc == 3 && std::string(argv[2]) == "true";

    if (filePath.substr(filePath.find_last_of(".") + 1) != "txt") {
        std::cout << "File must be a .txt file" << std::endl;
        return 1;
    }

    std::vector<int> data = readData(filePath);
    std::vector<int> sorted = mergeSort(data);

    if (writeOutput) {
        writeData("result.txt", sorted);
    }

    return 0;
}