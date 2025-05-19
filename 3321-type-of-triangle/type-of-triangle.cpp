class Solution {
public:
    string triangleType(vector<int>& nums) {
        string ans = "";
        if((nums[0] + nums[1] <= nums[2]) || (nums[0] + nums[2] <= nums[1]) || (nums[1] + nums[2] <= nums[0])) ans = "none";
       else if(nums[0] == nums[1] && nums[1] == nums[2]) ans = "equilateral";
    else if(nums[0] != nums[1] && nums[1] != nums[2] && nums[0] != nums[2]) ans = "scalene";
        else ans = "isosceles";
    return ans;
    }
};