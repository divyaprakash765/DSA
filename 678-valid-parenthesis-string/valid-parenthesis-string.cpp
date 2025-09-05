class Solution {
public:
vector<vector<int>> dp;
bool helper(string s,int cnt,int ind){ 
    if(cnt < 0) return false;
    if(ind == s.length()) return cnt == 0;
    if(dp[ind][cnt] != -1) return dp[ind][cnt];
    if(s[ind] == '('){
       return helper(s,cnt+1,ind+1);
    }
    if(s[ind] == ')'){
        return helper(s,cnt-1,ind+1);
    }
   
        return dp[ind][cnt] = helper(s,cnt+1,ind+1) || helper(s,cnt-1,ind+1) || helper(s,cnt,ind+1);
}
    bool checkValidString(string s) {
    dp.assign(101, vector<int>(101, -1));
     return helper(s,0,0);
    }
};