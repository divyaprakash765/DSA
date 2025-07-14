class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int idx0 = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                idx0 = i;
                break;
            }
        }
        if(idx0 != -1){
        for(int i=idx0+1;i<n;i++){
            if(nums[i] != 0){
                swap(nums[i],nums[idx0]);
                idx0++;
            }
        }
        }
    }
};