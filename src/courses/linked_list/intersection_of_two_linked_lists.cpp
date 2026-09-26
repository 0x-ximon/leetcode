struct Node {
    int val;
    Node* next;
    Node* prev;
};

class Solution {
   public:
    Node* getIntersectionNode(Node* headA, Node* headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        Node* p = headA;
        Node* q = headB;

        while (p != q) {
            p = p == nullptr ? headB : p->next;
            q = q == nullptr ? headA : q->next;
        }

        return p;
    }
};
