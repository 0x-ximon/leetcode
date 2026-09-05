#include <cstdlib>
#include <vector>

class Solution {
   public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int n = nums.size();

        std::vector<int> result(n);
        int p = 0;
        int q = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[p]) > abs(nums[q])) {
                result[i] = nums[p] * nums[p];
                p++;
            } else {
                result[i] = nums[q] * nums[q];
                q--;
            }
        }

        return result;
    }
};
