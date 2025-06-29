class Solution {
public:
    int MOD = 1e9 + 7;
    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> pow2(n, 1);
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2LL) % MOD;
        }

        int i = 0, j = n - 1;
        int ans = 0;
        
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                ans = (ans + pow2[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }
        
        return ans;
    }
};
