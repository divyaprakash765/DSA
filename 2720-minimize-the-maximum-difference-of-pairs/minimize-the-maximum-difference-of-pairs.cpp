class Solution {
public:

    bool canform_pair(vector<int>& nums,int p,int maxDiff){
        int n = nums.size();
        int pairs = 0;

        int i=0;
        while(i < n-1 && p > pairs){
            if(nums[i+1]-nums[i] <= maxDiff){
                pairs++;
                i += 2;
            } else i++;
        }
        return pairs >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
       if(p == 0) return 0;
       sort(nums.begin(),nums.end());

       int low = 0;
       int high = nums[n-1]-nums[0];
       int ans;
       while(low <= high){
        int mid = low + (high - low)/2;
        if(canform_pair(nums,p,mid)){
            high = mid-1;
            ans = mid;
        } else{
            low = mid+1;
        }
       }
       return ans;
    }
};