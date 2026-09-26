struct Node {
    int val;
    Node* next;
    Node* prev;
};

class Solution {
   public:
    bool hasCycle(Node* head) {
        if (head == nullptr || head->next == nullptr) return false;

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }

        return false;
    }
};
