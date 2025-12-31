#include <algorithm>
#include <expected>
#include <utility>
#include <vector>

#include "../utils/helpers.cpp"

enum HeapError { HeapEmpty };

// A Max-Heap Implementation in C++
template <typename T>
struct Heap {
    std::vector<T> data;
    Heap() {}

    void heapifyUp(std::size_t index) {
        while (index > 0) {
            auto parent_index = (index - 1) / 2;

            if (this->data[parent_index] >= this->data[index]) break;
            std::swap(this->data[parent_index], this->data[index]);
            index = parent_index;
        }
    }

    void heapifyDown(std::size_t index) {
        auto size = this->data.size();

        while (this->LeftChild(index) < size) {
            auto leftChildIndex = this->LeftChild(index);
            auto rightChildIndex = this->RightChild(index);

            auto largerChildIndex =
                (rightChildIndex < size) && (this->data[rightChildIndex] >
                                             this->data[leftChildIndex])
                    ? rightChildIndex
                    : leftChildIndex;

            if (this->data[index] >= this->data[largerChildIndex]) break;
            std::swap(this->data[index], this->data[largerChildIndex]);
            index = largerChildIndex;
        }
    }

    std::expected<T, HeapError> peek() {
        if (this->data.size() == 0)
            return std::unexpected(HeapError::HeapEmpty);
        else
            return std::expected(this->data[0]);
    }

    std::expected<T, HeapError> extract() {
        if (this->data.size() == 0)
            return std::unexpected(HeapError::HeapEmpty);

        auto result = this->data[0];
        auto size = this->data.size();

        this->data[0] = this->data[size - 1];
        data.pop_back();

        this->heapifyDown(0);
        return result;
    }

    void insert(T value) {
        this->data.push_back(value);

        auto size = this->data.size();
        this->heapifyUp(size - 1);
    }

    auto LeftChild(std::size_t index) { return (2 * index) + 1; }
    auto RightChild(std::size_t index) { return (2 * index) - 1; }
    void display() { Helpers::printContainer(this->data); }
};
