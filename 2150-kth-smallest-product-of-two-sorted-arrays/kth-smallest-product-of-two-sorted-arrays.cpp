typedef long long ll;
class Solution {
public:
   int cntposprod(ll x,vector<int>& nums2,ll m){
        int n = nums2.size();
        ll l = -1, r = n;
        while(l+1<r){
            ll j = (l+r)/2;
            if(x*nums2[j] <= m){
                l = j;
            }
            else{
                r = j;
            }
        }
        return l+1;
    }
    int cntnegprod(ll x,vector<int>& nums2,ll m){
        int n = nums2.size();
        ll l = -1, r = n;
        while(l+1<r){
            ll j = (l+r)/2;
            if(x*nums2[j] > m){
                l = j;
            }
            else{
                r = j;
            }
        }
        return n-r;
    }
    bool isGood(ll m, vector<int>& nums1,vector<int>& nums2, ll k){
        // cnt no. of products <= m
        ll cnt = 0;
        for(auto x : nums1){
            // x* num2[j] <= m
            if(x>0){ // pos
                // cnt of all products x*nums2[j] <= m
                cnt += cntposprod(x,nums2,m);
            }
            else if(x==0){ //0
                // 0 * 1st num2 ,.... all elements
                if(m>=0) cnt+= nums2.size();
            }
            else{ // neg
                cnt += cntnegprod(x,nums2,m);
            }
        }
        return (cnt>=k);
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll l = -1e10 -1 , r = 1e10 + 1;
        while(l<=r-2){
            ll m = (l+r)/2;
            if(isGood(m,nums1,nums2,k)){ // (no. of prod<=m) >= k
                r = m;
            }
            else{ // (no. of prod<=m) < k 
                l = m;
            }
        }
        return r;
    }
};