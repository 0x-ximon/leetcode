struct Node {
    int val;
    Node* next;
    Node* prev;
    Node* child;
};

class Solution {
   public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        Node* p = head;

        while (p != nullptr) {
            // Continue if there is no child node.
            if (p->child == nullptr) {
                p = p->next;
                continue;
            }

            // Store child in a temporary variable and get the tail of the child
            // list.
            Node* temp = p->child;
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            // Connect tail with p->next.
            temp->next = p->next;
            if (p->next != nullptr) p->next->prev = temp;

            p->next = p->child;
            p->child->prev = p;
            p->child = nullptr;
        }

        return head;
    }
};
