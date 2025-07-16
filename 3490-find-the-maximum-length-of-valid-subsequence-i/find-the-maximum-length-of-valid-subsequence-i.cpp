class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return 2;

        bool isOdd = true;
        int ans = 1;
        int mx = 1;
        int idx = 0;
        while(nums[idx]%2 == 0 && idx < n) idx++;
        
        for(int i=idx;i<n;i++){
            if(!isOdd && nums[i]%2 != 0){
                mx++;
                isOdd = !isOdd;
            }
            if(isOdd && nums[i]%2 == 0){
                mx++;
                isOdd = !isOdd;
            }
        }
        ans = max(mx,ans);

        idx = 0;
        while(nums[idx]%2 != 0 && idx < n) idx++;
        
        mx = 1;
        isOdd = true;
        for(int i=idx;i<n;i++){
            if(isOdd && nums[i]%2 != 0){
                mx++;
                isOdd = !isOdd;
            }
            if(!isOdd && nums[i]%2 == 0){
                mx++;
                isOdd = !isOdd;
            }
        }
        ans = max(ans,mx);

        int cntO = 0;
        int cntE = 0;
        for(int i=0;i<n;i++){
            if(nums[i] & 1){
                cntO++;
            } else{
                cntE++;
            }
        }

        ans = max(ans,max(cntO,cntE));

        return ans;

    }
};