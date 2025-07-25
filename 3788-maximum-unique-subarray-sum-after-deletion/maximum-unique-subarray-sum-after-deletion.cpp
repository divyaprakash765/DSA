class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int ans = 0;
        for(auto& it : s){
            if(it > 0) ans += it;
        }
        if(ans == 0){
            ans = INT_MIN;
            for(auto& it : s){
                ans = max(ans,it);
            }
        }

        return ans;
    }
};