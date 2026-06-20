#include <set>
#include <string>

class Solution {
   public:
    int maxDistinct(std::string str) {
        std::set<char> s = {};
        int k = 0;

        for (size_t i = 0; i < str.size(); i++) {
            if (s.find(str[i]) != s.end()) continue;
            s.insert(str[i]);
            k++;
        }

        return k;
    }
};
