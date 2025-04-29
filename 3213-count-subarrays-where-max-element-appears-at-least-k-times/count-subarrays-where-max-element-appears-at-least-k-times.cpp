class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());

        int cnt = 0;

        int i = 0;
        int j = 0;
        long long ans = 0;

        while(j < n){
            if(nums[j] == mx) cnt++;
            
            while(i < n && cnt >= k){
                ans += n-j;
                if(nums[i] == mx) cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};