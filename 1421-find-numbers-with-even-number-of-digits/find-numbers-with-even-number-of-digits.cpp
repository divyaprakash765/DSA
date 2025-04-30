class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(auto& num : nums){
            string s = to_string(num);
            int size = s.size();
            if(size%2 == 0) ans++;
        }
        return ans;
    }
};