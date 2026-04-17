class Solution {
public:
    vector<int> f(int n){
        vector<int> prime(n+1,0);
        prime[1] = 1;
        for(int i=2;i<=n;i++){
            if(prime[i] != 0) continue;
            for(int j=2*i;j<=n;j+=i){
                prime[j] = 1;
            }
        }
        return prime;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> prime = f(1e6);
        int ans = 0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(i & 1){
                while(prime[num] == 0){
                    ans++;
                    num++;
                }
            } else{
                if(prime[num] == 1){
                    while(prime[num] == 1){
                        num++;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};