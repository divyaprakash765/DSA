class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int left = nums[0];
        int ans = 0;

        for(int i=1;i<n-1;i++){
            if(nums[i] == nums[i+1]) continue;

            if(nums[i] > left && nums[i] > nums[i+1]){
                ans++;
            }
            if(nums[i] < left && nums[i] < nums[i+1]){
                ans++;
            }
            left = nums[i];
        }

        return ans;
    }
};