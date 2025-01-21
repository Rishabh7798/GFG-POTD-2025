// Linked List Group Reverse

/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
         int len = getLength(head);
        Node* origH = nullptr;
        Node* origT = nullptr;
        Node* tmpH = nullptr;
        Node* tmpT = nullptr;
        Node* curr = head;

        while (len > 0) {
            int j = k;
            j = std::min(j, len);
            while (j > 0) {
                Node* nex = curr->next;
                if (tmpH == nullptr) {
                    tmpH = curr;
                    tmpT = curr;
                } else {
                    curr->next = tmpH;
                    tmpH = curr;
                }
                curr = nex;
                j--;
                len--;
            }

            if (origH == nullptr) {
                origH = tmpH;
                origT = tmpT;
            } else {
                origT->next = tmpH;
                origT = tmpT;
            }

            tmpH = nullptr;
            tmpT = nullptr;
        }

        if (origT != nullptr) {
            origT->next = nullptr;
        }

        return origH;
    }

    int getLength(Node* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }
};
