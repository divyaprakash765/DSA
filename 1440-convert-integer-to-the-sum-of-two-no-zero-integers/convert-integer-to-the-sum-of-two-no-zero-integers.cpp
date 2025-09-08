class Solution {
public:

    bool not_zero(int num){
        string s = to_string(num);
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int a = i;
            int b = n-i;
            if(not_zero(a) && not_zero(b)){
                return {a,b};
            }
        }
        return {};
    }
};