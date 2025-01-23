// Clone List with Next and Random
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

// 1) with extra space
class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        if (head == nullptr) return nullptr;

        // Map to store the mapping of original nodes to their corresponding cloned nodes
        unordered_map<Node*, Node*> nodeMapping;
        
        // Dummy node to start building the cloned list
        Node* dummyNode = new Node(0);
        Node* currentOriginalNode = head;
        Node* currentClonedNode = dummyNode;
        
        // Step 1: Create a clone of the linked list with only next pointers
        while (head != nullptr) {
            Node* clonedNode = new Node(head->data);
            currentClonedNode->next = clonedNode;
            nodeMapping[head] = clonedNode;
            currentClonedNode = clonedNode;
            head = head->next;
        }
        
        // Step 2: Update the random pointers in the cloned list
        Node* clonedHead = dummyNode->next; // Head of the cloned list
        while (currentOriginalNode != nullptr) {
            if (currentOriginalNode->random != nullptr) {
                clonedHead->random = nodeMapping[currentOriginalNode->random];
            }
            clonedHead = clonedHead->next;
            currentOriginalNode = currentOriginalNode->next;
        }
        
        return dummyNode->next;
    }
};

// 2) with no extra space
class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        if (head == NULL)
            return head;

        Node *t = head;
        while (t != NULL) {
            Node *n = new Node(t->data);
            n->next = t->next;
            t->next = n;
            t = n->next;
        }

        t = head;
        Node *head2 = head->next;
        while (t != NULL) {
            if (t->random == NULL)
                t->next->random = NULL;
            else
                t->next->random = t->random->next;

            t = t->next->next;
        }

        t = head;
        Node *res = head->next;
        while (t != NULL) {
            Node *temp = t->next;
            t->next = temp->next;
            if (temp->next)
                temp->next = temp->next->next;
            t = t->next;
        }
        return head2;
    }
};
