class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = 0;
   
        for(int i=0;i<n;i++){
            unordered_set<int> s2;
            for(int j=i;j<n;j++){
            s2.insert(nums[j]);
            if(s2.size() == s.size()) ans++;
            }
        }
        return ans;
    }
};