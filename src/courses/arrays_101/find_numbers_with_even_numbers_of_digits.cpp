#include <string>
#include <vector>

class Solution {
   public:
    int findNumbers(std::vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            std::string number = std::to_string(nums[i]);
            if (number.size() % 2 == 0) count++;
        }

        return count;
    }
};
