class Solution {
public:
    using ll = long long;

    ll area(const vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        int top = INT_MAX, left = INT_MAX;
        int bottom = INT_MIN, right = INT_MIN;
        for (int i = r1; i < r2; i++) {
            for (int j = c1; j < c2; j++) {
                if (grid[i][j]) {
                    top = min(top, i);
                    left = min(left, j);
                    bottom = max(bottom, i);
                    right = max(right, j);
                }
            }
        }
        if (top == INT_MAX) return 0; // no 1's
        return (ll)(bottom - top + 1) * (right - left + 1);
    }

    long long minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        ll ans = LLONG_MAX;

        // 1. Three vertical partitions
        for (int i = 1; i < m; i++) {
            for (int j = i+1; j < m; j++) {
                ll a1 = area(grid, 0, n, 0, i);
                ll a2 = area(grid, 0, n, i, j);
                ll a3 = area(grid, 0, n, j, m);
                ans = min(ans, a1+a2+a3);
            }
        }

        // 2. Three horizontal partitions
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                ll a1 = area(grid, 0, i, 0, m);
                ll a2 = area(grid, i, j, 0, m);
                ll a3 = area(grid, j, n, 0, m);
                ans = min(ans, a1+a2+a3);
            }
        }

        // 3. Two vertical + one horizontal (and vice versa)
        for (int cut = 1; cut < n; cut++) {
            for (int mid = 1; mid < m; mid++) {
                // top half split vertically
                ll a1 = area(grid, 0, cut, 0, mid);
                ll a2 = area(grid, 0, cut, mid, m);
                ll a3 = area(grid, cut, n, 0, m);
                ans = min(ans, a1+a2+a3);

                // bottom half split vertically
                a1 = area(grid, 0, cut, 0, m);
                a2 = area(grid, cut, n, 0, mid);
                a3 = area(grid, cut, n, mid, m);
                ans = min(ans, a1+a2+a3);
            }
        }

        // 4. Two horizontal + one vertical
        for (int cut = 1; cut < m; cut++) {
            for (int mid = 1; mid < n; mid++) {
                // left half split horizontally
                ll a1 = area(grid, 0, mid, 0, cut);
                ll a2 = area(grid, mid, n, 0, cut);
                ll a3 = area(grid, 0, n, cut, m);
                ans = min(ans, a1+a2+a3);

                // right half split horizontally
                a1 = area(grid, 0, n, 0, cut);
                a2 = area(grid, 0, mid, cut, m);
                a3 = area(grid, mid, n, cut, m);
                ans = min(ans, a1+a2+a3);
            }
        }

        return ans;
    }
};
