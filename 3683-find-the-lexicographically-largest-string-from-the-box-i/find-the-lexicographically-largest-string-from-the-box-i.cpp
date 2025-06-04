class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        vector<int> v;
        char ch = *max_element(word.begin(),word.end());
        int n = word.size();
        int len = n - numFriends + 1;
        string ans = "";
        for(int i=0;i<n;i++){
            if(ch == word[i]) v.push_back(i);
        }
        for(int i=0;i<v.size();i++){
            string temp = (len <= n-v[i]) ? word.substr(v[i],len) : word.substr(v[i]);
            ans = max(ans,temp);
        }
        return ans;
    }
};