Meeting Rooms III

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());

        // Available rooms (min-heap)
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) available.push(i);

        // Busy rooms: (end_time, room_number)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        // Count of meetings per room
        vector<int> roomCount(n, 0);

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // Free up rooms whose meetings ended before current meeting starts
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            int duration = end - start;

            if (!available.empty()) {
                // Assign to smallest available room
                int room = available.top(); available.pop();
                busy.push({start + duration, room});
                roomCount[room]++;
            } else {
                // Delay meeting to when earliest room is free
                pair<long long, int> next = busy.top(); busy.pop();
                long long freeTime = next.first;
                int room = next.second;
                busy.push({freeTime + duration, room});
                roomCount[room]++;
            }
        }

        // Find room with max count
        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; i++) {
            if (roomCount[i] > maxMeetings) {
                maxMeetings = roomCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
