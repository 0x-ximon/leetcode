#include <vector>

class Solution {
   public:
    bool validMountainArray(std::vector<int>& arr) {
        // Check if array length is greater than 3
        if (arr.size() < 3) return false;

        // Check if array starts by decreasing
        if (arr[0] > arr[1]) return false;

        bool increasing = true;

        for (size_t i = 0; i < arr.size() - 1; i++) {
            // break if array is neither increasing nor decreasing
            if (arr[i] == arr[i + 1]) {
                return false;
            }

            // set decreasing to false if we encounter our first decrease
            if (increasing && arr[i] > arr[i + 1]) {
                increasing = !increasing;
                continue;
            }

            // break if array was decreasing but now increasing
            if (!increasing && arr[i] < arr[i + 1]) {
                return false;
            }
        }

        return true && !increasing;
    }
};
