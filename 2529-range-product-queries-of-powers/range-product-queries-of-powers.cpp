class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                power.push_back(1 << i);
            }
        }

        int m = power.size();
        vector<long long> prefix(m + 1, 1);
        for (int i = 0; i < m; i++) {
            prefix[i + 1] = (prefix[i] * power[i]) % mod;
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long res = (prefix[r + 1] * powmod(prefix[l], mod - 2)) % mod;
            ans.push_back((int)res);
        }
        return ans;
    }

    long long powmod(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
};
