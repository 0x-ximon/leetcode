struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
   public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto dummy = new ListNode(0, head);

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
