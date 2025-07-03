class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int min_idx = -1;
        int max_idx = -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
         if(nums[i] < mini){
            min_idx = i;
            mini = nums[i];
         }
         if(nums[i] > maxi){
            max_idx = i;
            maxi = nums[i];
         }
        }

        int ans = min((min(min_idx + 1,max_idx + 1) + (n - max(min_idx,max_idx))),min(max(min_idx + 1,max_idx + 1),max(n-min_idx,n-max_idx)));

        return ans;
    }
};