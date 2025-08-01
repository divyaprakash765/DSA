class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        for(int i=0;i<n;i++){
            time[i] = time[i]%60;
        }

        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += mp[(60-time[i])%60];
            mp[time[i]]++;
        }

        return ans;
    }
};