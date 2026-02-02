#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Helpers {
    template <typename T>
    static void printContainer(T const& range) {
        std::cout << "\t[";
        for (auto const& item : range) {
            std::cout << " " << item << ",";
        }
        std::cout << " ]\n";
    }

    static void printMap(const std::map<std::string, int>& m) {
        std::cout << "{\n";
        for (const auto& [key, value] : m) {
            std::cout << "  " << key << ": " << value << "\n";
        }
        std::cout << "}\n";
    }

    static void printMap(const std::map<int, int>& m) {
        std::cout << "{\n";
        for (const auto& [key, value] : m) {
            std::cout << "  " << key << ": " << value << "\n";
        }
        std::cout << "}\n";
    }

    static void printMap(const std::map<int, std::vector<int>>& m) {
        std::cout << "{\n";
        for (const auto& [key, vec] : m) {
            std::cout << "  " << key << ": [";

            for (size_t i = 0; i < vec.size(); ++i) {
                std::cout << vec[i];
                if (i < vec.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]\n";
        }
        std::cout << "}\n";
    }
};
