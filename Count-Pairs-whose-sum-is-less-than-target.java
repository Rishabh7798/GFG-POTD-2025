Count Pairs whose sum is less than target - https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-pairs-whose-sum-is-less-than-target

// User function Template for Java
class Solution {
    int countPairs(int arr[], int target) {
        Arrays.sort(arr);
        int left = 0;
        int right = arr.length - 1;
        int count = 0;
        
        while (left < right) {
            if (arr[left] + arr[right] < target) {
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        
        return count;
    }
}
