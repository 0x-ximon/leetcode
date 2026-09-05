#include <vector>

class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int p = 0;
        int q = nums.size() - 1;

        while (p != q) {
            int sum = nums[p] + nums[q];

            if (sum == target) return {p + 1, q + 1};
            if (sum < target) p++;
            if (sum > target) q--;
        }

        return {p, q};
    }
};
