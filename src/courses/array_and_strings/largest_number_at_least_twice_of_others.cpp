#include <vector>

class Solution {
   public:
    int dominantIndex(std::vector<int>& nums) {
        int k = 0;  // Index of the mazimum.

        for (auto i = 0; i < nums.size(); i++)
            if (nums[i] > nums[k]) k = i;

        for (auto i = 0; i < nums.size(); i++) {
            if (i != k && nums[i] * 2 > nums[k]) return -1;
        }

        return k;
    }
};
