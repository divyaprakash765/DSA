class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        for(int i=1;i<=n;i++) num.push_back(i);
        k--;
        while(k--){
            next_permutation(num.begin(),num.end());
        }
        string ans = "";
        for(int i=0;i<n;i++){
            ans += (num[i]+'0');
        }
        return ans;
    }
};