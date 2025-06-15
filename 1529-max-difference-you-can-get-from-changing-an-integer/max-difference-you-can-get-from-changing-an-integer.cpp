class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();

        int x = s[0]-'0';
        string maxi = "";
        
        int i = 0;
        while(i < n && x == 9){
            maxi += s[i];
            i++;
           if(i != n) x = s[i]-'0';
        }

        while(i < n){
            if(s[i]-'0' == x){
                maxi += '9';
            } else{
                maxi += s[i];
            }
            i++;
        }

        string mini = "";

        x = s[0]-'0';
        i = 0;

        while(i < n && (x == 1 || x == 0)){
            mini += s[i];
            i++;
            if(i != n) x = s[i]-'0';
        }
        char replace = '1';
        if(i != 0) replace = '0';
        while(i < n){
            if(s[i]-'0' == x){
                mini += replace;
            } else{
                mini += s[i];
            }
            i++;
        }

        return stoi(maxi) - stoi(mini);

    }
};