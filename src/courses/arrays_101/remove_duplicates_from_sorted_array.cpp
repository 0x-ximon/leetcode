#include <vector>

class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int k = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
