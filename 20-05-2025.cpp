Burning Tree

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Step 1: Create parent mapping and find target node
    void markParents(Node* root, unordered_map<Node*, Node*>& parent_track, Node* &targetNode, int target) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front(); q.pop();
            if (current->data == target) {
                targetNode = current;
            }
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
    
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_track;
        Node* targetNode = NULL;
        
        // Step 1: Map parents and find target node
        markParents(root, parent_track, targetNode, target);
        
        // Step 2: BFS to simulate burning
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool anyNewBurned = false;
            for (int i = 0; i < size; i++) {
                Node* current = q.front(); q.pop();
                
                if (current->left && !visited[current->left]) {
                    anyNewBurned = true;
                    visited[current->left] = true;
                    q.push(current->left);
                }
                if (current->right && !visited[current->right]) {
                    anyNewBurned = true;
                    visited[current->right] = true;
                    q.push(current->right);
                }
                if (parent_track[current] && !visited[parent_track[current]]) {
                    anyNewBurned = true;
                    visited[parent_track[current]] = true;
                    q.push(parent_track[current]);
                }
            }
            if (anyNewBurned) time++;
        }
        
        return time;
    }
};
