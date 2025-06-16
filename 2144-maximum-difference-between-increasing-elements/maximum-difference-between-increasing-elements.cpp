class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[n-1];
        int mini = nums[n-1];
        int ans = -1;

        for(int i=n-2;i>=0;i--){
           if(nums[i] > maxi){
            maxi = nums[i];
            mini = nums[i];
           }
           if(nums[i] < mini){
            mini = nums[i];
           }
           if(maxi == mini) continue;
           ans = max(ans,maxi-mini);
        }
        return ans;
    }
};