class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        int cnt = 0;
        while(ss >> word){
            int n = word.size();
            bool temp = true;
            for(int i=0;i<n;i++){
                if(brokenLetters.find(word[i]) != string::npos){
                   temp = false;
                   break;
                }
            }
            if(temp) cnt++;
        }
        return cnt;
    }
};