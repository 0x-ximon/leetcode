struct Node {
    int val;
    Node* next;
    Node* prev;
};

class Solution {
   public:
    Node* reverseList(Node* head) {
        Node* prevNode = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;

        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }

        return prevNode;
    }
};
