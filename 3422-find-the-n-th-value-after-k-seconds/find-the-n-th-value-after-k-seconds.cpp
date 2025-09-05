class Solution {
public:
int mod = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<int> nums(n,1);

        for(int i=0;i<k;i++){
            for(int i=1;i<n;i++){
                nums[i] = (nums[i-1] + nums[i])%mod;
            }
        }
        return nums[n-1];
    }
};