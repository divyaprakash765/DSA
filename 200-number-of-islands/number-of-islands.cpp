class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void bfs(vector<vector<char>>& grid,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        grid[x][y] = '#';
        for(auto& d : dir){
            int x_ = x + d[0];
            int y_ = y + d[1];
        if(x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) continue;
        if(grid[x_][y_] == '#' || grid[x_][y_] == '0') continue;
        grid[x_][y_] = '#';
            q.push({x_,y_});
        }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '0' || grid[i][j] == '#') continue;
                bfs(grid,i,j);
                ans++;
            }
        }
        return ans;
    }
};