class Solution {
public:
    typedef long long ll;

    long long flowerGame(int n, int m) {

        if(n == 1 && m == 1) return 0;
        ll no_of_odds_in_n = 0;
        ll no_of_evens_in_n = n/2;
        ll no_of_odds_in_m = 0;
        ll no_of_evens_in_m = m/2;
        
        if(n & 1){
            no_of_odds_in_n = (n/2) + 1;
        } else{
            no_of_odds_in_n = n/2;
        }

         if(m & 1){
            no_of_odds_in_m = (m/2) + 1;
        } else{
            no_of_odds_in_m = m/2;
        }
        ll ans = no_of_odds_in_n*no_of_evens_in_m + no_of_odds_in_m*no_of_evens_in_n;

        return ans;
    }
};