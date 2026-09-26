#include <cstdint>

struct Node {
    int val;
    Node* next;
    Node* prev;
};

class Solution {
   public:
    Node* rotateRight(Node* head, int k) {
        if (head == nullptr) return nullptr;

        // Variables for traversing the list.
        Node* p = head;  // New Head
        Node* q = head;  // Holds the tail
        uint64_t n = 1;

        // Convert list into a bounded list and Get the number of elements in
        // the list.
        while (q->next != nullptr) {
            q = q->next;
            n++;
        }

        q->next = head;

        // Update the value of K to prevent needless multiple iterations over
        // the list.
        k %= n;

        // Find the node that needs to become the end. It would be at position
        // n - k.
        if (k != 0) {
            for (auto i = 0; i < n - k; i++) {
                q = q->next;
            }
        }

        // Make the target tail node the head node and reconvert list to a
        // singly linked list.
        p = q->next;
        q->next = nullptr;
        return p;
    }
};
