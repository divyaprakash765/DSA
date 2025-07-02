class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size();

        map<string,int> mp;
        vector<string> ans;
        mp[string(1,s[0])] = 1;
        ans.push_back(string(1,s[0]));

        int i = 1;
        string temp = "";

        while(i<n){
            temp += s[i];

            if(mp[temp] == 0){
                ans.push_back(temp);
                mp[temp]++;
                temp = "";
            }
            i++;
        }
        return ans;
    }
};