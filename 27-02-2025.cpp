Get Min from Stack

class Solution {
  int min;
    stack<int> st;
    
public:
    Solution() {}

    // Add an element to the top of the Stack
    void push(int x) {
        if (st.empty()) {
            min = x;
        } else if (x <= min) {
            st.push(min);
            min = x;
        }
        st.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        if (st.empty()) 
            return;
        int tmp = st.top();
        st.pop();
        if (tmp == min && !st.empty()) {
            min = st.top();
            st.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        if (st.empty()) 
            return -1;
        return st.top();
    }

    // Finds minimum element of the Stack
    int getMin() {
        if (st.empty()) 
            return -1;
        return min;
    }
};
