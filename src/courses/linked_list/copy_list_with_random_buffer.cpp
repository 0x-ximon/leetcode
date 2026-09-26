#include <map>

struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        this->val = _val;
        this->next = nullptr;
        this->random = nullptr;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        std::map<Node*, Node*> old_to_new = {};

        Node* p = head;
        while (p != nullptr) {
            old_to_new[p] = new Node(p->val);
            p = p->next;
        }

        p = head;
        while (p != nullptr) {
            old_to_new[p]->next = old_to_new[p->next];
            old_to_new[p]->random = old_to_new[p->random];
            p = p->next;
        }

        return old_to_new[head];
    }
};
