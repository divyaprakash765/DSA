class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        int ans = 0;
        int curr = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == mx){
                curr++;
            } else{
                ans = max(curr,ans);
                curr = 0;
            }
        }
        ans = max(curr,ans);
        return ans;
    }
};
