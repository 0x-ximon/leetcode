struct Node {
    int val;
    Node* next;
    Node* prev;
};

class Solution {
   public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* p = list1;
        Node* q = list2;

        if (p == nullptr) {
            return q;
        }

        if (q == nullptr) {
            return p;
        }

        if (p->val < q->val) {
            p->next = this->mergeTwoLists(p->next, q);
            return p;
        } else {
            q->next = this->mergeTwoLists(p, q->next);
            return q;
        }
    }
};
