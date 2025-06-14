class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        int remap_num = -1;

        for(int i=0;i<s.size();i++){
            if(s[i] == '9') continue;
            else{
                remap_num = s[i]-'0';
                break;
            }
        }
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]-'0' == remap_num){
                ans += '9';
            } else{
                ans += s[i];
            }
        }
        int maxi = stoi(ans);

        remap_num = s[0]-'0';

        ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]-'0' == remap_num) ans += '0';
            else ans += s[i];
        }
        int mini = stoi(ans);
        return maxi - mini;
    }
};