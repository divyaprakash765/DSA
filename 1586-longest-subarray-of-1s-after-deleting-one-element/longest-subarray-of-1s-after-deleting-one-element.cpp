class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int i = 0;
        int j = 0;
        int ans = 0;

        while(j < n){
            if(nums[j] == 0) cnt0++;
            while(cnt0 == 2){
                if(nums[i] == 0) cnt0--;
                i++;
            }
            ans = max(ans,j-i);
            j++;
        }
        return ans;
    }
};