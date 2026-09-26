struct Node {
    int val;
    Node* next;

    Node(int _val) {
        this->val = _val;
        this->next = nullptr;
    }
};

class Solution {
   public:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node preHead = Node{0};
        Node* p = &preHead;
        int carry = 0;

        while (l1 || l2 || carry) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            carry += a + b;

            p->next = new Node(carry % 10);
            carry /= 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            p = p->next;
        }

        return preHead.next;
    }
};
