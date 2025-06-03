class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false), hasKey(n, false), opened(n, false);

        queue<int> q;
        for (int box : initialBoxes) {
            hasBox[box] = true;
        }

        int ans = 0;
        bool changed = true;

        while (changed) {
            changed = false;
            for (int i = 0; i < n; ++i) {
                if (!opened[i] && hasBox[i] && (status[i] == 1 || hasKey[i])) {
                    opened[i] = true;
                    changed = true;
                    ans += candies[i];

                    for (int b : containedBoxes[i]) {
                        hasBox[b] = true;
                    }

                    for (int k : keys[i]) {
                        hasKey[k] = true;
                    }
                }
            }
        }

        return ans;
    }
};
