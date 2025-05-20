class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1,0);

        for(auto& query : queries){
            int start = query[0];
            int end = query[1];
            diff[start]--;
            diff[end+1]++;
        }

        int r_sum = 0;
        for(int i=0;i<n;i++){
            r_sum += diff[i];
            nums[i] += r_sum;
            if(nums[i] > 0) return false;
        }
        return true;
    }
};