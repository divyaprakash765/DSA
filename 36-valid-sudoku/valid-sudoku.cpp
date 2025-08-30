class Solution {
public:

    bool isValid(vector<vector<char>>& board,char ch,int row,int col){
        for(int i=0;i<9;i++){
            if(i != row && board[i][col] == ch) return false;
            if(i != col && board[row][i] == ch) return false;
            int i_ = 3*(row/3) + i/3;
            int j_ = 3*(col/3) + i%3;
            if((i_ != row || j_ != col) && board[i_][j_] == ch) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                if(!isValid(board,board[i][j],i,j)) return false;
            }
        }
        return true;
    }
};