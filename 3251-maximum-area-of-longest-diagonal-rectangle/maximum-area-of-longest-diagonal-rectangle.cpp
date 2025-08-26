class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int area = 0;
        double diagnol = 0;
        for(auto& it : dimensions){
        int l = it[0];
        int w = it[1];
        int d = l*l + w*w;
        if(d >= diagnol){
            if(d == diagnol) area = max(l*w,area);
            else area = l*w;
            diagnol = d;
        }
        }
        return area;
    }
};