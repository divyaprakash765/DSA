class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j] > num) ans = max(nums[j]-num,ans);
            }
        }
        return ans;
    }
};