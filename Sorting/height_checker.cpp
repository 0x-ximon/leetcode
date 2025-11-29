#include <algorithm>
#include <vector>

class Solution {
   public:
    int heightChecker(std::vector<int>& heights) {
        int k = 0;

        auto sorted = heights;
        std::sort(sorted.begin(), sorted.end());

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sorted[i]) k++;
        }

        return k;
    }
};
