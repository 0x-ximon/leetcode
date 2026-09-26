struct Node {
    int val;
    Node* next;
    Node* prev;
};

class Solution {
   public:
    Node* oddEvenList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};
