struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class Solution {
   public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        Node* head;
        Node* next;

        if (list1->val <= list2->val) {
            head = list1;
            next = mergeTwoLists(list1->next, list2);
            head->next = next;
        } else {
            head = list2;
            next = mergeTwoLists(list1, list2->next);
            head->next = next;
        }

        return head;
    }
};
