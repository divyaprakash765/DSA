class Solution {
public:

    void set_matrix(vector<vector<int>>& matrix,int i,int j){
        int n = matrix.size();
        int m = matrix[0].size();

        for(int k=0;k<n;k++){
            matrix[k][j] = 0;
        }
        for(int k=0;k<m;k++){
            matrix[i][k] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> zero_pos;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    zero_pos.push_back({i,j});
                }
            }
        }
        for(int i=0;i<zero_pos.size();i++){
            set_matrix(matrix,zero_pos[i][0],zero_pos[i][1]);
        }
    }
};