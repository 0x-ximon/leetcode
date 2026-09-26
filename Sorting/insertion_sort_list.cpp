struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {};
    Node(int x) : val(x), next(nullptr) {};
    Node(int x, Node* next) : val(x), next(next) {};
};

class Solution {
   public:
    Node* insertionSortList(Node* head) {
        if (!head || !head->next) return head;
        auto dummy = new Node(0, head);

        auto curr = head->next;
        auto prev = head;

        while (curr) {
            if (curr->val >= prev->val) {
                curr = curr->next;
                prev = prev->next;
                continue;
            }

            prev->next = curr->next;
            auto cursor = dummy;

            while (cursor->next->val < curr->val) {
                cursor = cursor->next;
            }

            curr->next = cursor->next;
            cursor->next = curr;

            curr = prev->next;
        }

        return dummy->next;
    }
};
