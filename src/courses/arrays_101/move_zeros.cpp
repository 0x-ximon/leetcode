#include <vector>

class Solution {
   public:
    void moveZeroes(std::vector<int>& nums) {
        int n = nums.size();
        size_t i = 0;
        size_t j = 0;

        while (i < n) {
            if (j == n) {
                nums[i] = 0;
                i++;
                continue;
            }

            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
                j++;
                continue;
            }

            j++;
        }
    }
};
