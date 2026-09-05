#include <algorithm>
#include <climits>
#include <vector>

class Solution {
   public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int min = INT_MAX;
        int sum = 0;

        int i = 0;
        int j = 0;

        while (j < nums.size()) {
            sum += nums[j];
            j++;

            while (sum >= target) {
                min = std::min(min, j - i);
                sum -= nums[i];
                i++;
            }
        }

        return min == INT_MAX ? 0 : min;
    }
};
