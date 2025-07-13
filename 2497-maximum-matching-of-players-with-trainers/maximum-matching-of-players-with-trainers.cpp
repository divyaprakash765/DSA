class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
       
       int ans = 0;
       int i = 0;
       int j = 0;

       while(i<n && j<m){
        if(players[i] <= trainers[j]){
            ans++;
            i++;
            j++;
        } else{
            j++;
        }
       }

       return ans;
        
    }
};