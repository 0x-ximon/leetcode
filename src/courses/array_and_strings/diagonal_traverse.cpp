#include <map>
#include <vector>

class Solution {
   public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
        std::vector<int> result = {};
        std::map<int, std::vector<int>> diagonals = {};

        // Store out each diagonal in its own vector.
        for (auto i = 0; i < mat.size(); i++) {
            for (auto j = 0; j < mat[i].size(); j++) {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }

        bool isReversed = true;

        // Iterate through the map keys and add each element to the result
        // array.
        for (const auto [key, vec] : diagonals) {
            if (isReversed) {
                for (int i = vec.size() - 1; i >= 0; --i) {
                    result.push_back(vec[i]);
                }
            } else {
                for (int i = 0; i < vec.size(); ++i) {
                    result.push_back(vec[i]);
                }
            }

            isReversed = !isReversed;
        }

        return result;
    };
};
