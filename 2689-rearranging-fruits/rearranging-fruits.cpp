class Solution {
public:
    typedef long long ll;

    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        int n = basket1.size();

        for (int i = 0; i < n; i++) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
        }

        vector<int> surplus;
        int globalMin = INT_MAX;

        for (auto& [val, count] : freq) {
            if (count % 2 != 0) return -1;  // Impossible
            int half = abs(count) / 2;
            for (int i = 0; i < half; i++) {
                surplus.push_back(val);
            }
            globalMin = min(globalMin, val);
        }

        sort(surplus.begin(), surplus.end());

        ll ans = 0;
        for (int i = 0; i < surplus.size() / 2; i++) {
            ans += min(surplus[i], 2 * globalMin);
        }

        return ans;
    }
};
