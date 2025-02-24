Stock span problem

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            if(st.empty()) ans[i]=i+1;
            else ans[i]=i-st.top();
            st.push(i);
        }
        return ans;
    }
};
