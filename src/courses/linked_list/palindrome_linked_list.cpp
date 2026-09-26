struct Node {
    int val;
    Node* next;
    Node* prev;
};

class Solution {
   public:
    bool isPalindrome(Node* head) {
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;
        Node* temp = nullptr;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        prev = slow;
        slow = slow->next;
        prev->next = nullptr;

        while (slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        fast = head;
        slow = prev;

        while (slow) {
            if (fast->val != slow->val) {
                return false;
            } else {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return true;
    }
};
