// Subarrays with sum K

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        int sum=0,ans=0;
        unordered_map<int,int> mm;
        for(int x:arr){
            sum+=x;
            if(sum==k)ans++;
            ans+=mm[sum-k];
            mm[sum]++;
        }
        return ans;
    }
};
