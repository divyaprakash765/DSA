class Solution {
public:
typedef long long ll;
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int z = 0;
        int o = 0;
        ll val = 0;
        ll pow = 1;
        for(char ch : s){
            if(ch == '0') z++;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1'){
            if(val + pow > k) continue;
            val += pow;
            o++;
            }
            pow <<= 1;
            if(pow > k) break;
        }
        return o + z;
    }
};