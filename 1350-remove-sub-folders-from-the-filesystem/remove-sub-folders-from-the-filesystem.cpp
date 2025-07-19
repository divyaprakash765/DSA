class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());

        set<string> s;
        vector<string> ans;
        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=0;j<folder[i].size();j++){
             if(j != 0 && folder[i][j] == '/'){
                if(s.find(temp) != s.end()){
                    temp = "";
                    break;
                } else{
                  temp += folder[i][j];
                }
             } else{
                temp += folder[i][j];
             }
            }
            if(temp == "") continue;
            else{
                ans.push_back(temp);
                s.insert(temp);
            }
        }

        return ans;
    }
};