class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<long long> roomUsage(n, 0); // to count usage per room
        priority_queue<int, vector<int>, greater<>> freeRooms; // min-heap of room numbers
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy; // {endTime, roomNo}

        for (int i = 0; i < n; ++i) freeRooms.push(i);

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            // Free up rooms that are done before the current meeting starts
            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                roomUsage[room]++;
                busy.push({end, room});
            } else {
                auto [nextFree, room] = busy.top(); busy.pop();
                long long duration = end - start;
                busy.push({nextFree + duration, room});
                roomUsage[room]++;
            }
        }

        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (roomUsage[i] > roomUsage[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;
    }
};
