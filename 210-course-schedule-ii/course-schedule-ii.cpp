class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        int n = prerequisites.size();

        for(auto it : prerequisites){
            mp[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(auto& it : mp[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : mp[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int>{};
    }
};