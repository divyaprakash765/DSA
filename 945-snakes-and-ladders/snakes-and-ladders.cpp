class Solution {
public:

    pair<int,int> get_coordinates(int num,int n){
        int r = (num-1)/n;
        int c = (num-1)%n;
        int i = n-1-r;
        int j = (r%2 == 0) ? c : n-1-c;
        return {i,j};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<int> visited(n*n+1,0);

        queue<pair<int,int>> q;
        q.push({1,0});
        visited[1] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int pos = it.first;
            int moves = it.second;

            if(pos == n*n) return moves;

            for(int k=1;k<=6;k++){
                int next = pos + k;
                if(next > n*n) continue;
                auto [i,j] = get_coordinates(next,n);
                if(board[i][j] != -1) next = board[i][j];
                if(!visited[next]){
                  visited[next] = 1;
                  q.push({next,moves+1});
                }
            }
        }
    return -1;
    }
};