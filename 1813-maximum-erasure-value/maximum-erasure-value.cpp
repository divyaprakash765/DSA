class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
        set<int> s;

        while(j<n){
        while(s.find(nums[j]) != s.end()){
            s.erase(nums[i]);
            sum -= nums[i];
            i++;
        }
        sum += nums[j];
        ans = max(ans,sum);
        s.insert(nums[j]);
        j++;
        }

        return ans;
    }
};