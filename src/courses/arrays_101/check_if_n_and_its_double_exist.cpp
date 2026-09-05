#include <cstddef>
#include <vector>

class Solution {
   public:
    bool checkIfExist(std::vector<int>& arr) {
        for (size_t i = 0; i < arr.size(); i++) {
            for (size_t j = 0; j < arr.size(); j++) {
                if (arr[i] == arr[j] * 2 && i != j) return true;
            }
        }

        return false;
    }
};
