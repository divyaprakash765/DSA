class Solution {
public:
    vector<vector<int>> directions = {{1,1},{1,-1},{-1,-1},{-1,1}};

    int f(int i,int j,int dir,bool flag, int targ,vector<vector<int>>& grid){
       
       int ni = i + directions[dir][0];
       int nj = j + directions[dir][1];

       int n = grid.size();
       int m = grid[0].size();
       if(ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] != targ){
        return 0;
       }

       int nottaketurn = 1 + f(ni,nj,dir,flag,2 - targ,grid);
       int taketurn = 0;
       if(flag){
        taketurn = 1 + f(ni,nj,(dir+1)%4,!flag,2-targ,grid);
       }
       return max(taketurn,nottaketurn);
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        bool flag = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    for(int dir=0;dir<4;dir++){
                    ans = max(ans,1 + f(i,j,dir,flag,2,grid));
                    }
                }
            }
        }
        return ans;
    }
};