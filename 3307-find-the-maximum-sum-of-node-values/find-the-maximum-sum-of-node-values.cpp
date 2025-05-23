class Solution {
public:
typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        int count = 0;
        int min_loss = INT_MAX;

        for(ll num : nums){
            if((num ^ k) > num){
                count++;
                sum += (num^k);
            } else{
                sum += num;
            }

            min_loss = min((ll)min_loss,abs(num-(num^k)));
        }
        if(count & 1){
            return sum - min_loss;
        }
        return sum;
    }
};