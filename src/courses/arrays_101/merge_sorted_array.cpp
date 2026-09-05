#include <vector>

class Solution {
   public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (size_t i = nums1.size(); i > 0; i--) {
            if (n == 0) {
                nums1[i - 1] = nums1[m - 1];
                m--;
                continue;
            }

            if (m == 0) {
                nums1[i - 1] = nums2[n - 1];
                n--;
                continue;
            }

            if (nums1[m - 1] >= nums2[n - 1]) {
                nums1[i - 1] = nums1[m - 1];
                if (m != 0) m--;
                continue;
            }

            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[i - 1] = nums2[n - 1];
                if (n != 0) n--;
                continue;
            }
        }
    }
};
