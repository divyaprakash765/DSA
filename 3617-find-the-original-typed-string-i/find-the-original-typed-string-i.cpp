class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;
        for(int i=n-1;i>0;i--){
            if(word[i] == word[i-1]){
                ans++;
            }
        }
        return ans;
    }
};