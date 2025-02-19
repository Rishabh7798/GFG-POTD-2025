Merge K sorted linked lists

/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;  // Min-heap based on node value
    }
};

class Solution {
public:
    // Function to merge K sorted linked lists
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        
        // Push the head of each linked list into the priority queue
        for (Node* node : arr) {
            if (node) {
                pq.push(node);
            }
        }
        
        Node* newHead = nullptr, *tail = nullptr;
        
        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();
            
            if (!newHead) {
                newHead = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            
            if (temp->next) {
                pq.push(temp->next);
            }
        }
        return newHead;
    }
};
