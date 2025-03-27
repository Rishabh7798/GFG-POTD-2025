Activity Selection

class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<pair<int, int>> activities;
        
        // Store activities with (finish time, start time)
        for (int i = 0; i < n; i++) {
            activities.push_back({finish[i], start[i]});
        }
        
        // Sort activities by finish time
        sort(activities.begin(), activities.end());

        int count = 1; // First activity is always selected
        int lastFinishTime = activities[0].first;

        // Iterate through sorted activities
        for (int i = 1; i < n; i++) {
            if (activities[i].second > lastFinishTime) {
                count++;
                lastFinishTime = activities[i].first;
            }
        }

        return count;
    }
};
