#include <cstddef>

struct Node {
    int val;
    Node* next;
    Node* prev;
};

class Solution {
   public:
    Node* removeNthFromEnd(Node* head, int n) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        Node* p = head;
        Node* q = head;

        for (size_t i = 0; i < n; i++) {
            p = p->next;
        }

        if (p == nullptr) {
            return head->next;
        }

        while (p->next != nullptr) {
            p = p->next;
            q = q->next;
        }

        q->next = q->next->next;
        return head;
    }
};
