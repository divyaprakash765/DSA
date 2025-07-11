class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int len = to_string(nums[0]).size();
        long long ans = 0;

        for (int pos = 0; pos < len; ++pos) {
            vector<int> freq(10, 0);
            for (int num : nums) {
                string s = to_string(num);
                freq[s[pos] - '0']++;
            }

            for (int i = 0; i < 10; ++i) {
                ans += (long long)freq[i] * (n - freq[i]);
            }
        }

        return ans / 2; 
    }
};
