#include <algorithm>
#include <vector>

class Solution {
   public:
    int heightChecker(std::vector<int>& heights) {
        int k = 0;

        std::vector<int> copy{};
        copy.resize(heights.size());

        for (size_t i = 0; i < heights.size(); i++) {
            copy[i] = heights[i];
        }

        sort(heights.begin(), heights.end());
        for (size_t i = 0; i < heights.size(); i++) {
            if (copy[i] != heights[i]) k++;
        }

        return k;
    }
};
