#include <string>
#include <vector>

class Solution {
   public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string result = "";

        if (strs.empty()) return result;
        if (strs.size() == 1) return strs[0];

        int min = strs[0].length();
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].length() < min) min = strs[i].length();
        }

        for (int i = 0; i < min; i++) {
            bool isValid = true;
            char c = strs[0][i];

            for (int j = 0; j < strs.size(); j++)
                if (strs[j][i] != c) isValid = false;

            if (isValid)
                result += c;
            else
                return result;
        }

        return result;
    }
};
