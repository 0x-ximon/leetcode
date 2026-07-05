#include <vector>

class Solution {
   public:
    void sortColors(std::vector<int>& nums) {
        int counts[3] = {0, 0, 0};
        for (auto index : nums) counts[index]++;

        int p = 0;
        int q = 0;
        while (q < nums.size()) {
            while (counts[p] == 0) p++;
            nums[q] = p;
            counts[p]--;
            q++;
        }
    }
};
