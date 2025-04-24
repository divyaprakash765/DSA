class Solution {
public:
typedef long long ll;

    int sum_of_sqr_digit(int n){
        ll ans = 0;
        while(n > 0){
            int rem = n % 10;
            ans += rem*rem;
            n = n/10;
        }
        return ans;
    }

    bool isHappy(int n) {
        unordered_map<ll,ll> mp;
        
        while( n != 1){
        if(mp.find(n) != mp.end()) return false;
        mp[n] = 1;
        n = sum_of_sqr_digit(n);
        }
        return true;
    }
};