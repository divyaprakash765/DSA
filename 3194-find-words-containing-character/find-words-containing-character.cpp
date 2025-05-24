class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int i = 0;
        for(auto& word:words){
         for(int j=0;j<word.size();j++){
            if(word[j] == x){
                ans.push_back(i);
                break;
            }
         }
          i++;
        }
        return ans;
    }
};