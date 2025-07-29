class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> last_set_bits(32,-1);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<31;j++){
                if(nums[i] & (1<<j)){
                    last_set_bits[j] = i;
                } 
            }
        int last = i;
        for(int j=0;j<31;j++){
            if(last_set_bits[j] != -1){
                last = max(last,last_set_bits[j]);
            }
        }
        ans[i] = last-i+1;
        }
        
        
    return ans;
    }
};