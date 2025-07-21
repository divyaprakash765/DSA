class Solution {
    int mod = 1e9+7;
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        map<int,int> left;
        map<int,int> right;
        long long ans = 0;
         
         for(int i=n-1;i>0;i--){
            right[nums[i]]++;
         }
         left[nums[0]]++;

         for(int i=1;i<n;i++){
            int num = 2 * nums[i];
            right[nums[i]]--;

            long long leftCount = left[num] % mod;
            long long rightCount = right[num] % mod;

            ans = (ans + (leftCount * rightCount) % mod) % mod;

            left[nums[i]]++;
         }
    return ans;
    }
};