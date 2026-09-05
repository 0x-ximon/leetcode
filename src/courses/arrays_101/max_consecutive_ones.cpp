#include <vector>

class Solution {
   public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int max = 0;
        int p1 = 0;
        int p2 = 0;

        while (p1 < n) {
            if (nums[p1] == 1) {
                int localMax = 0;

                for (p2 = p1; p2 < n; p2++) {
                    if (nums[p2] == 1)
                        localMax++;
                    else {
                        p2 = p1;
                        break;
                    }
                }

                if (localMax > max) max = localMax;
            }

            p1++;
        }

        return max;
    }
};
