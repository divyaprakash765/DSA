class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int> mp; 
        mp[{dominoes[0][0],dominoes[0][1]}]++;
       if(dominoes[0][1] != dominoes[0][0]) mp[{dominoes[0][1],dominoes[0][0]}]++;
        int ans = 0;

        for(int i=1;i<dominoes.size();i++){
        int u = dominoes[i][0];
        int v = dominoes[i][1];
        if(mp.find({u,v}) != mp.end()){
            ans += mp[{u,v}];
            mp[{u,v}]++;
           if(u != v) mp[{v,u}]++;
        } else{
            mp[{u,v}]++;
            if(u != v) mp[{v,u}]++;
        }
        }
        return ans;
    }
};