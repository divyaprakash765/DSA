class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();

        vector<string> ans;
        string t = "";
        int i = 0;
        while(i<n){
            if(i+k < n){
                string temp = s.substr(i,k);
                ans.push_back(temp);
                i += k;
            }
            else{
                t += s.substr(i,n);
                break;
            }
        }
        int num = 0;
       if(n%k) num = k - n%k;
        for(int j=0;j<num;j++){
            t += fill;
        }
        ans.push_back(t);
        return ans;
    }
};