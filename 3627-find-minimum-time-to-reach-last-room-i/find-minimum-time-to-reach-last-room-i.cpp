class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> arrival_time(n,vector<int>(m,INT_MAX));
        arrival_time[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});

        while(!pq.empty()){
            int time = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            if(time > arrival_time[i][j]) continue;
            for(auto& d : dir){
                int i_ = i + d[0];
                int j_ = j + d[1];
                if(i_ < 0 || j_ < 0 || i_ >= n || j_ >= m) continue;
                int newTime = max(time, moveTime[i_][j_]) + 1;
                if(newTime < arrival_time[i_][j_]) {
                    arrival_time[i_][j_] = newTime;
                    pq.push({newTime,i_,j_});
                }
            }
        }
        return arrival_time[n-1][m-1];
    }
};