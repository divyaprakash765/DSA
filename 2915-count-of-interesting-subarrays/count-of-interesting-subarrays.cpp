class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        long long ans = 0;
        int cnt = 0;
        unordered_map<int,long long> mp;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            if(nums[i]%modulo == k) cnt++;

            int rem = cnt%modulo;
            int needed = (rem - k + modulo)%modulo;
            ans += mp[needed];
            mp[rem]++;
        }

        
        return ans;
    }
};