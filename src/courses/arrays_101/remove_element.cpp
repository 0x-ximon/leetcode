#include <vector>

class Solution {
   public:
    int removeElement(std::vector<int>& nums, int val) {
        size_t i = 0;
        size_t j = 0;

        while (j < nums.size()) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }

            j++;
        }

        return i;
    }
};
