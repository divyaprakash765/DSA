class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans(n/3,vector<int>(3));
        int l = 0;
        for(int i=0;i<n/3;i++){
           for(int j=0;j<3;j++){
            ans[i][j] = nums[l];
            l++;
           }
        }
        bool temp = true;
        for(int i=0;i<n/3;i++){
            int first = ans[i][0];
            int second = ans[i][1];
            int third = ans[i][2];
            if(second - first > k) temp = false;
            if(third - second > k) temp = false;
            if(third - first > k) temp = false;
        }

        if(temp) return ans;
        return {};
    }
};