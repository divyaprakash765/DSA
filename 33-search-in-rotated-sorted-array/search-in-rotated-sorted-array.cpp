class Solution {

    // {4,5,6,7,0,1,2}

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[low] <= nums[mid]){ // left part of nums is sorted
               if(target >= nums[low] && target < nums[mid]){ // target is present in left part
                high = mid-1;
               } else{ // target is present in right part
                 low = mid+1;
               }
            } else{ // right part of nums is sorted
               if(target > nums[mid] && target <= nums[high]){
                low = mid+1;
               } else{
                high = mid-1;
               }
            }
        }
        return -1;
    }
};