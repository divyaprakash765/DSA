class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        string vowel = "";
        for(int i=0;i<n;i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
           vowel += s[i];
        }
        }
        sort(vowel.begin(),vowel.end());
        string ans = "";
        int idx = 0;
        for(int i=0;i<n;i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
           ans += vowel[idx];
           idx++;
        } else{
            ans += s[i];
        }
        }
        return ans;
    }
};