class Solution {
    public:
    void sortColors(vector < int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int m = i;
            
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[m]) m = j;
            }
            
            swap(nums[i], nums[m]);
        }
    }
};