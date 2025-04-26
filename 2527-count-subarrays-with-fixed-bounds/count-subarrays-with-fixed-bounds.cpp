class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int minK_pos = -1;
        int maxK_pos = -1;
        int culp_idx = -1;

        for(int i=0;i<n;i++){
            if(nums[i] == minK) minK_pos = i;
            if(nums[i] == maxK) maxK_pos = i;
            if(nums[i] < minK || nums[i] > maxK) culp_idx = i;
            long long smaller = min(minK_pos,maxK_pos);
            long long temp = smaller - culp_idx;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};