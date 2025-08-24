class Solution {
public:
    int minOperations(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
        }
        int ans = 0;
        for(auto it : mp){
            int freq = it.second;
            if(freq == 1) return -1;
            if(freq % 3 == 0){
                ans += freq/3;
            } else {
                ans += (freq/3) + 1;
            }
        }

        return ans;
    }
};