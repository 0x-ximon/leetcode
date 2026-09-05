#include <string>
#include <vector>

class Solution {
   public:
    std::string reverseWords(std::string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right && s[left] == ' ') left++;
        while (left < right && s[right] == ' ') right--;

        std::vector<std::string> words;
        std::string word;

        while (left <= right) {
            if (s[left] != ' ')
                word += s[left];
            else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }

            left++;
        }

        if (!word.empty()) words.push_back(word);

        std::string reversed = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            reversed += words[i];
            if (i != 0) reversed += ' ';
        }

        return reversed;
    }
};
