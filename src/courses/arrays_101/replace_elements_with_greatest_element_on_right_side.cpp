#include <vector>

class Solution {
   public:
    std::vector<int> replaceElements(std::vector<int>& arr) {
        for (size_t i = 0; i < arr.size(); i++) {
            int max = 0;

            for (size_t j = i + 1; j < arr.size(); j++)
                if (arr[j] > max) max = arr[j];

            if (i == arr.size() - 1)
                arr[i] = -1;
            else
                arr[i] = max;
        }

        return arr;
    }
};
