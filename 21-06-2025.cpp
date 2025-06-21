Police and Thieves

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        queue<int> police, thief;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                police.push(i);
            } else if (arr[i] == 'T') {
                thief.push(i);
            }

            // Try to match the front elements of both queues
            while (!police.empty() && !thief.empty()) {
                int p = police.front();
                int t = thief.front();

                if (abs(p - t) <= k) {
                    // Match found
                    count++;
                    police.pop();
                    thief.pop();
                } else if (t < p) {
                    // Thief too far left
                    thief.pop();
                } else {
                    // Policeman too far left
                    police.pop();
                }
            }
        }

        return count;
    }
};
