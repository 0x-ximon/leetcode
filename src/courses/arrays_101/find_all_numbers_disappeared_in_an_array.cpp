#include <cstdlib>
#include <vector>

class Solution {
   public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int> answer = {};
        size_t n = nums.size();

        for (size_t i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = abs(nums[index]) * -1;
        }

        for (size_t i = 0; i < n; i++) {
            if (nums[i] > 0) answer.push_back(i + 1);
        }

        return answer;
    }
};
