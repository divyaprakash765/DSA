class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++) hash[i] = i;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if((nums[i]%nums[j] == 0) && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
        }
        
        int len = -1;
        int last_idx = -1;
        for(int i=0;i<n;i++){
            if(dp[i] > len){
                len = dp[i];
                last_idx = i;
            }
        }

        vector<int> ans;
        while(hash[last_idx] != last_idx){
            ans.push_back(nums[last_idx]);
            last_idx = hash[last_idx];
        }
        ans.push_back(nums[last_idx]);

        return ans;

    }
};