class Solution {
public:
    bool hamming_dist(string a,string b){
        if(a.size() != b.size()) return false;
        int cnt = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]) cnt++;
            if(cnt > 1) return false; 
        }
        return cnt == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);

        for(int i=0;i<n;i++){
            hash[i] = i;
        for(int prev_idx = 0;prev_idx <= i-1;prev_idx++){
            if((hamming_dist(words[i],words[prev_idx])) && groups[i] != groups[prev_idx] && 1 + dp[prev_idx] > dp[i]){
                dp[i] = 1 + dp[prev_idx];
                hash[i] = prev_idx;
            }
        }
        }

        int size = -1;
        int last_idx = -1;

        for(int i=0;i<n;i++){
            if(dp[i] > size){
                size = dp[i];
                last_idx = i;
            }
        }
        vector<string> ans;
        ans.push_back(words[last_idx]);

        while(last_idx != hash[last_idx]){
            last_idx = hash[last_idx];
            ans.push_back(words[last_idx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};