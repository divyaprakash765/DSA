class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
             if(k==0) return 1;
        vector<double> dp(n+1); // dp[i] => prob. u reached i at some point
        dp[0] = 1;
        double win = 1;
        for(int i=1;i<=n;i++){
            dp[i] = win/maxPts;
            if(i<k){ // keep incrementing the right side until u reach goal of k
                win += dp[i];
            }
            if(i>=maxPts && i-maxPts<k){
                win -= dp[i-maxPts];
            }
        }
        double ans = 0;
        for(int i=k;i<=n;i++){
            ans += dp[i];
        }
        return ans;


    }
};