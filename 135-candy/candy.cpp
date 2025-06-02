class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        left[0] = 1;
        for(int i=1;i<n;i++){
            if(ratings[i-1] < ratings[i]){
            left[i] = 1 + left[i-1];
            } else{
                left[i] = 1;
            }
        }
        vector<int> right(n);
        right[n-1] = 1;
        for(int i=n-2;i>=0;i--){
           if(ratings[i+1] < ratings[i]){
            right[i] = 1 + right[i+1];
           } else{
            right[i] = 1;
           }
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            ans += max(left[i],right[i]);
        }
        return ans;        
    }
}; 