#include <vector>

class Solution {
   public:
    int pivotIndex(std::vector<int>& nums) {
        int leftSum = 0;
        int totalSum = 0;

        for (auto i = 0; i < nums.size(); i++) totalSum += nums[i];

        // We check the sum before each index and compare if it's equal to the
        // total minus the current element.
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum * 2 == totalSum - nums[i]) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
