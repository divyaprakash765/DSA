class Solution {
public:
    
    bool is_valid(vector<vector<char>>& board,int row,int col,char c){

        for(int i=0;i<=8;i++){
            if(board[row][i] == c) return false;
            if(board[i][col] == c) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }

    bool f(vector<vector<char>>& board){
        
        for(int i=0;i<=8;i++){
            for(int j=0;j<=8;j++){
                if(board[i][j] == '.'){
                    for(char ch = '1';ch <= '9';ch++){
                        if(is_valid(board,i,j,ch)){
                            board[i][j] = ch;
                            if(f(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};