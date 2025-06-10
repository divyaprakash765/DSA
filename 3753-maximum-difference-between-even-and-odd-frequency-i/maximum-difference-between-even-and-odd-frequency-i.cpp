class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();

        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int maxi_odd = 0;
        int mini_even = INT_MAX;

        for(int i=0;i<26;i++){
           if(freq[i] & 1) maxi_odd = max(maxi_odd,freq[i]);
           else if(freq[i] != 0 && freq[i]%2 == 0) mini_even = min(mini_even,freq[i]);
        }
        int ans = maxi_odd - ((mini_even == INT_MAX) ? 0 : mini_even);

        return ans;
    }
};