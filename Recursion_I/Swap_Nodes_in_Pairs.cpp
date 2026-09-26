struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class Solution {
   public:
    Node* swapPairs(Node* head) { return exchange(head); }
    Node* exchange(Node* node) {
        if (!node || !node->next) return node;

        Node* next = exchange(node->next->next);
        Node* head = node->next;

        head->next = node;
        node->next = next;

        return head;
    }
};
