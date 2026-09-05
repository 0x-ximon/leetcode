#include <string>
#include <utility>

class Solution {
   public:
    std::string reverseWords(std::string s) {
        if (s.length() <= 1) return s;

        int fast = 1;
        int slow = 0;

        while (fast < s.length()) {
            // Beginning of word
            if (s[fast] != ' ' && s[fast - 1] == ' ') slow = fast;

            // End of Word
            else if (s[fast] == ' ' && s[fast - 1] != ' ')
                reverse(s, slow, fast - 1);

            fast++;
        }

        // Reverse last word
        reverse(s, slow, fast - 1);
        return s;
    }

   private:
    void reverse(std::string& s, int start, int end) {
        while (start < end) {
            std::swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
