#include <string>

class Solution {
   public:
    int strStr(std::string haystack, std::string needle) {
        int m = haystack.length();
        int n = needle.length();

        for (int i = 0; i < m; i++) {
            if (haystack[i] != needle[0]) continue;

            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (haystack[j + i] != needle[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) return i;
        }

        return -1;
    }
};
