class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for(auto& it : mp){
            int g_size = it.first;
            vector<int> g = it.second;
            for(int i=0;i<g.size();i+=g_size){
                vector<int> temp;
                for(int j=0;j<g_size;j++){
                    temp.push_back(g[i+j]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};