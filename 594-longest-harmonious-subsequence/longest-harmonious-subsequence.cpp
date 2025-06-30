class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int ans = 0;
        for(int i=0;i<n;i++){
        int num = mp[nums[i]];
        if(mp.find(nums[i]+1) != mp.end()){
            num += mp[nums[i]+1];
        }
        else num = 0;
        ans = max(ans,num);
        }
        return ans;
    }
};