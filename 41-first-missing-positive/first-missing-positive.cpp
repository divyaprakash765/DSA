class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long n = nums.size();
        set<long long> s(nums.begin(),nums.end());
        long long mini = *min_element(nums.begin(),nums.end());
        long long maxi = *max_element(nums.begin(),nums.end());
        long long ans;
        if(mini > 1) ans = mini-1;
        else ans = maxi+1;
        for(long long i=mini;i<=maxi;i++){
            if(i <= 0) continue;
            if(s.find(i) == s.end()){
                ans = i;
                break;
            }
        }
        if(mini > 1 || maxi < 1) ans = 1;
        return ans;
    }
};