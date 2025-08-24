class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            graph[u].push_back({v,wt});
        }

        unordered_map<int,int> dist;
        for(int i=1;i<=n;i++) dist[i] = INT_MAX;
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        set<int> vis;

        while(!pq.empty()){
          auto& it = pq.top();
          int wt = it.first;
          int node = it.second;

          if(vis.count(node)){
           pq.pop();
           continue;
          }
          vis.insert(node);
          
          pq.pop();
          for(auto& neighbor : graph[node]){
            if(!vis.count(neighbor.first) && wt + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = wt + neighbor.second;
                pq.push({neighbor.second + wt,neighbor.first});
            }
          }
        }

        int ans = 0;
        for(auto& it : dist){
            ans = max(ans,it.second);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};