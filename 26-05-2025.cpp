Insert in Sorted Circular Linked List

/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);
        
        // Case 1: Empty list
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }
        
        Node* curr = head;
        
        // Case 2: Inserting before head (i.e., new smallest or largest value)
        while (true) {
            // Case A: Normal position between two nodes
            if (curr->data <= data && data <= curr->next->data) {
                break;
            }
            // Case B: At the turning point from max to min (like 9->1)
            if (curr->data > curr->next->data) {
                if (data >= curr->data || data <= curr->next->data) {
                    break;
                }
            }
            curr = curr->next;
            // If we’ve looped the whole list, break
            if (curr == head) break;
        }
        
        newNode->next = curr->next;
        curr->next = newNode;
        
        // Update head if needed
        if (data < head->data) {
            return newNode;
        }
        return head;
    }
};
