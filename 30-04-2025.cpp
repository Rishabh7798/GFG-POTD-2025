Find length of Loop

class Solution {
  public:
    // Function to count the number of nodes in loop using Floyd’s Cycle Detection Algorithm
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect Loop
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop detected, count the length
                return countLoopLength(slow);
            }
        }

        // No loop
        return 0;
    }

  private:
    // Helper function to count the number of nodes in the loop
    int countLoopLength(Node* meetingPoint) {
        int count = 1;
        Node* current = meetingPoint->next;

        while (current != meetingPoint) {
            count++;
            current = current->next;
        }

        return count;
    }
};
