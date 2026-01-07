#include <utility>
#include <vector>

class Solution {
   private:
    std::size_t leftChild(int index) { return (2 * index) + 1; }
    std::size_t rightChild(int index) { return (2 * index) + 2; }

    void heapifyDown(std::vector<int>& array, std::size_t index,
                     std::size_t end) {
        while (this->leftChild(index) <= end) {
            auto left = this->leftChild(index);
            auto right = this->rightChild(index);

            auto larger =
                right <= end && array[right] > array[left] ? right : left;

            if (array[index] >= array[larger]) break;
            std::swap(array[index], array[larger]);
            index = larger;
        }
    };

   public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        if (nums.empty()) return nums;
        auto n = nums.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            this->heapifyDown(nums, i, n - 1);
        }

        for (int end = n - 1; end > 0; end--) {
            std::swap(nums[0], nums[end]);
            this->heapifyDown(nums, 0, end - 1);
        }

        return nums;
    }
};
