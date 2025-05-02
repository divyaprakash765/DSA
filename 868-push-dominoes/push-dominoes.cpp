class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> distL(n);

        int idx_l = -1;

        for(int i=n-1;i>=0;i--){
            if(dominoes[i] == 'L'){
            idx_l = i;
            distL[i] = 0;
            }
            else if(dominoes[i] == '.'){
               if(idx_l == -1) distL[i] = -1;
               else distL[i] = idx_l-i;
            }
            else{
               idx_l = -1;
               distL[i] = -1;
            }
        }

        int idx_r = -1;
        vector<int> distR(n);

        for(int i=0;i<n;i++){
            if(dominoes[i] == 'R'){
            idx_r = i;
            distR[i] = 0;
            }
            else if(dominoes[i] == '.'){
               if(idx_r == -1) distR[i] = -1;
               else distR[i] = i-idx_r;
            }
            else{
               idx_r = -1;
               distR[i] = -1;
            }
        }

        string ans = dominoes;

        for(int i=0;i<n;i++){
            if(distL[i] == distR[i]) ans[i] = '.';
            else if(distL[i] == -1) ans[i] = 'R';
            else if(distR[i] == -1) ans[i] = 'L';
            else if(distL[i] > distR[i]) ans[i] = 'R';
            else if(distL[i] < distR[i]) ans[i] = 'L';
        }
        return ans;
    }
};