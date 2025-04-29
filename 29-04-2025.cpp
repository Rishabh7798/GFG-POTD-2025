Sort a linked list of 0s, 1s and 2s

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // Count the number of 0s, 1s and 2s
        int count[3] = {0, 0, 0}; // count[0] for 0s, count[1] for 1s, count[2] for 2s
        
        Node* temp = head;
        
        // First pass: Count 0s, 1s and 2s
        while (temp != NULL) {
            count[temp->data]++;
            temp = temp->next;
        }
        
        temp = head;
        
        // Second pass: Update the linked list based on counts
        int i = 0;
        while (temp != NULL) {
            if (count[i] == 0) {
                i++;
            } else {
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }
        
        return head;
    }
};
