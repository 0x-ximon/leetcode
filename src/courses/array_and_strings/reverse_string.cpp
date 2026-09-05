#include <utility>
#include <vector>

class Solution {
   public:
    void reverseString(std::vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            std::swap(s[i], s[s.size() - i - 1]);
        }
    }
};
