class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int ans = 0;
        for(auto& word:words){
            mp[word]++;
        }
        bool has_middle = false;

        for(auto& [word,count]:mp){
          string rev = word;
          reverse(rev.begin(),rev.end());

          if(word != rev){
            if(mp.count(rev)){
            int pairs = min(count,mp[rev]);
            ans += pairs*4;
            mp[word] -= pairs;
            mp[rev] -= pairs;
            }
          } else{
            int pairs = count/2;
            ans += pairs*4;
            mp[word] -= pairs*2;
            if(mp[word] > 0) has_middle = true;
          }
        }

        if(has_middle) ans += 2;
        return ans;
    }
};