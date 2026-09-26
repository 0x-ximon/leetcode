struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class Solution {
   public:
    Node* reverseList(Node* head) { return reverse(head); }
    Node* reverse(Node* node) {
        if (!node || !node->next) return node;

        Node* head = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;

        return head;
    }
};
