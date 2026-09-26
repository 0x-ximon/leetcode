struct Node {
    int val;
    Node* next;
    Node* prev;
};

class Solution {
   public:
    Node* removeElements(Node* head, int val) {
        if (head == nullptr) return nullptr;

        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        if (head == nullptr) return nullptr;

        Node* p = head;
        Node* q = head;
        Node* r = nullptr;

        while (p != nullptr) {
            r = p->next;

            if (p->val != val) {
                q->next = p;
                q = q->next;
            }

            if (r == nullptr) {
                q->next = nullptr;
            }

            p = r;
        }

        return head;
    }
};
