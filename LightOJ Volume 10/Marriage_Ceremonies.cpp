#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (auto &sub : a) {
        for (int &i : sub) {
            cin >> i;
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(1 << n, -1));
    function<int(int, int)> fun = [&](int row, int mask) -> int {
        if (mask == (1 << n) - 1) return 0;

        if (dp[row][mask] != -1) return dp[row][mask];
        int ans = 0;
        for (int col = 0; col < n; col++) {
            if (!(mask >> col & 1)) {
                ans = max(ans, a[row][col] + fun(row + 1, mask | (1 << col)));
            }
        }
        return dp[row][mask] = ans;
    };
    // cout << fun(0, 0) << endl;

    function<int(void)> tabulation = [&]() -> int {
        vector<int> dp(1 << n, LLONG_MIN);
        dp[0] = 0;

        for (int row = 0; row < n; row++) {
            vector<int> new_dp(1 << n, LLONG_MIN);
            for (int mask = 0; mask < (1 << n); mask++) {
                if (dp[mask] == LLONG_MIN) continue;
                for (int col = 0; col < n; col++) {
                    if (!(mask & (1 << col))) { 
                        new_dp[mask | (1 << col)] = max(new_dp[mask | (1 << col)], dp[mask] + a[row][col]);
                    }
                }
            }
            dp = new_dp;
        }
        return dp[(1 << n) - 1];
    };
    cout << tabulation() << endl;
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}