#include <vector>

class Solution {
   public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        size_t i = 0;
        size_t j = nums.size() - 1;

        while (i < j) {
            if (nums[i] % 2 == 1) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;
            } else
                i++;
        }

        return nums;
    }
};
