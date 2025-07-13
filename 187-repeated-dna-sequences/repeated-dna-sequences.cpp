class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();

        unordered_map<string,int> mp;

        for(int i=0;i<=n-10;i++){
            string temp = "";
            for(int j=0;j<10;j++){
                temp += s[i+j];
            }
            mp[temp]++;
        }

        vector<string> res;
        for(auto& it : mp){
         if(it.second > 1){
            res.push_back(it.first);
         }
        }
        return res;
    }
};