class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size();
    
        int d = events[0][0];
        priority_queue<int,vector<int>,greater<int>> pq;

        int i = 0;
        int ans = 0;

        while(!pq.empty() || i < n){
            while(i < n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            d++;
            while(!pq.empty() && pq.top() < d) pq.pop();
        }
        return ans;
    }
};