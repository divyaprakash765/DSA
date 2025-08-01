class Solution {
public:
// [1,1,1,2,3,3,5]
//    i     j
//  if(nums[i] < nums[j]) i++ j++
// else j++;
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 0;
        while(j < n){
            if(nums[i] == nums[j]) j++;
            else{
                i++;
                j++;
            }
        }
        return i;
        
    }
};