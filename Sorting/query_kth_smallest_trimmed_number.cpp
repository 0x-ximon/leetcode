#include <array>
#include <cstdint>
#include <cstdlib>
#include <print>
#include <string>
#include <vector>

class Solution {
   public:
    std::vector<int> smallestTrimmedNumbers(std::vector<std::string>& nums, std::vector<std::vector<int>>& queries) {
        if (nums.size() == 0) return {};
        size_t m = nums.size();
        size_t n = nums[0].size();
        std::vector<int> result = {};

        std::vector<std::pair<int, std::string>> buffer;
        buffer.resize(m);

        for (auto query : queries) {
            int k = query[0];
            int t = query[1];

            for (unsigned int j = n - 1; j >= n - t; j--) {
                std::array<size_t, 10> counts = {};
                std::array<size_t, 10> starts = {};

                for (size_t i = 0; i < m; i++) {
                    uint8_t c = nums[i][j] - '0';
                    counts[c]++;
                }

                for (size_t i = 1; i < starts.size(); i++) {
                    starts[i] = counts[i - 1] + starts[i - 1];
                }

                for (size_t i = 0; i < m; i++) {
                    uint8_t c = nums[i][j] - '0';
                    buffer[starts[c]] = {i, nums[i]};
                    starts[c]++;
                }
            }

            std::print("Buffer: [ ");
            for (auto b : buffer) std::print("{}, ", b.first);
            std::println("];");

            result.push_back(buffer[k - 1].first);
        }

        return result;
    }

   private:
    void radixSort(std::vector<std::string>& arr) {
        size_t m = arr.size();
        size_t n = arr[0].size();

        std::vector<std::string> sorted;
        sorted.resize(m);

        for (int j = n - 1; j >= 0; j--) {
            std::array<size_t, 10> counts = {};
            std::array<size_t, 10> starts = {};

            // Record all counts for each column
            for (size_t i = 0; i < m; i++) {
                uint8_t c = arr[i][j] - '0';
                counts[c]++;
            }

            for (size_t k = 1; k < starts.size(); k++) {
                starts[k] = counts[k - 1] + starts[k - 1];
            }

            for (size_t i = 0; i < m; i++) {
                uint8_t c = arr[i][j] - '0';
                sorted[starts[c]] = arr[i];
                starts[c]++;
            }

            arr = sorted;
        }
    }
};

int main() {
    Solution solution{};
    std::vector<std::string> nums = {"102", "473", "251", "814"};
    std::vector<std::vector<int>> queries = {{1, 1}, {2, 3}, {4, 2}, {1, 2}};
    auto result = solution.smallestTrimmedNumbers(nums, queries);

    std::print("[ ");
    for (auto r : result) std::print("{}, ", r);
    std::println("];");
}
