class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> vowels(26,0);
        vector<int> conso(26,0);

        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vowels[s[i]-'a']++;
            } else{
                conso[s[i]-'a']++;
            }
        }
        int v = 0;
        int c = 0;
        for(int i=0;i<26;i++){
            v = max(vowels[i],v);
            c = max(conso[i],c);
        }
        return v + c;
    }
};