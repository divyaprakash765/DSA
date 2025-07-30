class Solution {
public:
    string maxValue(string s, int x) {
        int size = s.length();
        bool is_pos = (s[0] == '-') ? false : true;
        string ans = "";
        if(is_pos){
            int temp = -1;
            for(int i=0;i<size;i++){
                if(temp == -1 && s[i]-'0' < x){
                  ans += to_string(x);
                  ans += s[i];
                  temp = 1;
                } else{
                    ans += s[i];
                }
            }
            if(temp == -1) ans += to_string(x);
        } else{
            int temp = -1;
            for(int i=0;i<size;i++){
                if(temp == -1 && s[i]-'0' > x){
                  ans += to_string(x);
                  ans += s[i];
                  temp = 1;
                } else{
                    ans += s[i];
                }
            }
            if(temp == -1) ans += to_string(x);
        }

        return ans;
    }
};