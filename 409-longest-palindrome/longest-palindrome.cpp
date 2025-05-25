class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;

        for(auto& ch:s){
            mp[ch]++;
        }
        int ans = 0;
        for(auto& [ch,count]:mp){
            if(count >= 2){
             if(count & 1){
                ans += count-1;
                mp[ch] -= count-1;
             } else{
                ans += count;
                mp[ch] -= count;
             }
            }
        }
        for(auto& [ch,count]:mp){
            if(count == 1){
                ans++;
                break;
            }
        }
        return ans;
    }
};