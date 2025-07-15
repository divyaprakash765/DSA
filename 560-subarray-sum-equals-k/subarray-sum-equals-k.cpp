class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        mp[0] = 1;
        int pre = 0;
        int cnt = 0;

        for(int i=0;i<n;i++){
        pre += nums[i];
        
        cnt += mp[pre-k];
        mp[pre]++;
        }

        return cnt;
    }
};