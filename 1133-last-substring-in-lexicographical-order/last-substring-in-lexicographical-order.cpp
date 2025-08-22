class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        
        int i = 0;
        int j = 1;
        int k = 0;

        while(j < n){
            if(s[i+k] < s[j+k]){
                i = max(i+k+1,j);
                j = i+1;
                k = 0;
            } else if(s[i+k] > s[j+k]){
                j = j+k+1;
                k = 0;
            } else{
                k++;
            }
        }
        return s.substr(i);
    }
};