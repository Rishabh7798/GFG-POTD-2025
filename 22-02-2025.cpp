Longest valid Parentheses

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ')' && st.size() > 1 && s[st.top()] == '(') {
                st.pop();
            } else {
                st.push(i);
            }
        }
        int lim = s.length(), ans = 0;
        while(!st.empty()) {
            int p = st.top();
            st.pop();
            ans = max(ans, lim - p - 1);
            lim = p;
        }
        return ans;
    }
};
