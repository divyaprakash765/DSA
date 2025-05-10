class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        vector<vector<int>> arr_time(n,vector<int>(m,INT_MAX));
        arr_time[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        bool temp = true;
        while(!pq.empty()){
            int time = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
        for(auto& d : dir){
            int i_ = i + d[0];
            int j_ = j + d[1];
            if(i_ < 0 || j_ < 0 || i_ >= n || j_ >= m) continue;
            int num = (i+j)%2 + 1;
            int final_time = max(time,moveTime[i_][j_]) + num;
            if(arr_time[i_][j_] > final_time){
                arr_time[i_][j_] = final_time;
                pq.push({final_time,i_,j_});
            } 
        }
        }

        return arr_time[n-1][m-1];

    }
};