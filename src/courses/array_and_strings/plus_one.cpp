#include <vector>

class Solution {
   public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        int sum = 0;

        for (auto i = n - 1; i >= 0; i--) {
            // Add one to the last digit
            if (n - 1 == i) sum += 1;

            // Compute the sum
            sum += digits[i] + carry;

            // Save the remainder of the sumation
            digits[i] = sum % 10;

            // Recompute the carry
            carry = sum >= 10 ? 1 : 0;

            // Reinitialize sum
            sum = 0;
        }

        if (carry != 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};
