class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> mngi(n);

        for(int i=0;i<n;i++){
            int num = s[i]-'0';
            int idx = -1;
            for(int j=i+1;j<n;j++){
                if(s[j]- '0' >= num){
                    num = s[j] - '0';
                    idx = j;
                }
            }
            mngi[i] = idx;
        }


        string ans = s;

        for(int i=0;i<n;i++){
          if(mngi[i] != -1 && s[i] != s[mngi[i]]){
            ans[i] = s[mngi[i]];
            ans[mngi[i]] = s[i];
            break;
          }
        }

        return stoi(ans);
    }
};