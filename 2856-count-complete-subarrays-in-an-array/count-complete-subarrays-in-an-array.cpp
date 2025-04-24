class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        unordered_map<int,int> mp;
        int l = 0;
        for(int i=0;i<n;i++){
         mp[nums[i]]++;
         while(mp.size() == k){
          ans += n - i;
          mp[nums[l]]--;
          if(mp[nums[l]] == 0) mp.erase(nums[l]);
          l++;
         }
        }
        return ans;
    }
};