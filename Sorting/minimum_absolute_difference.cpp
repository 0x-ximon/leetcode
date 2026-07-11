#include <algorithm>
#include <limits>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        std::vector<std::vector<int>> result = {};

        std::sort(arr.begin(), arr.end());
        int m = std::numeric_limits<int>::max();

        for (int i = 1; i < arr.size(); i++) {
            int d = arr[i] - arr[i - 1];
            if (d < m) m = d;
        }

        for (int i = 1; i < arr.size(); i++) {
            int d = arr[i] - arr[i - 1];
            if (d == m) result.push_back({arr[i - 1], arr[i]});
        }

        return result;
    }
};
