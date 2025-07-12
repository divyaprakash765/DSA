class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        
       sort(nums.begin(),nums.end());

       int median;
       if(n & 1){
        median = nums[n/2];
       } else{
        median = (nums[n/2] + nums[(n/2)-1])/2;
       }
       
       int ops = 0;
       for(int i=0;i<n;i++){
        ops += abs(nums[i] - median);
       }

       return ops;
    }
};