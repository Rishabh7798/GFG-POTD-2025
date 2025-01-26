// Remove loop in Linked List

/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
         Node* slow = head;
        Node* fast = head;
        Node* prev = head;

        // Detect loop using Floyd's Cycle Detection algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            prev = fast;
            fast = fast->next->next;

            // If a loop is detected
            if (slow == fast) {
                slow = head;
                prev = prev->next;

                // Find the node before the start of the loop
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                    prev = prev->next;
                }

                // Break the loop
                prev->next = nullptr;
                return;
            }
        }
    }
};
