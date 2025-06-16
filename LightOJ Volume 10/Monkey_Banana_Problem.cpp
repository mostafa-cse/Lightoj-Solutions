#include <bits/stdc++.h>
#define int long long
using namespace std;
class Solution {
    public:
    int tabulation(vector<vector<int>> &a, int n) {
        for (int i = 1; i <= 2 * n - 1; i++) {
            for (int j = 1; j <= n; j++) {
                int mx = a[i - 1][j];
                if (i <= n) {
                    mx = max(mx, a[i - 1][j - 1]);
                } else {
                    if (j + 1 <= n)
                        mx = max(mx, a[i - 1][j + 1]);
                }
                a[i][j] += mx;
            }
        }
        return a[2 * n - 1][1];
    }
    int TopDown(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &a) {
        if (i < 1 or j < 1 or j > n or i > 2 * n - 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (i < n) {
            dp[i][j] = a[i][j] + max(TopDown(i + 1, j, n, dp, a), TopDown(i + 1, j + 1, n, dp, a));
        } else {
            dp[i][j] = a[i][j] + max(TopDown(i + 1, j, n, dp, a), TopDown(i + 1, j - 1, n, dp, a));
        }
        return dp[i][j];
    }
};
signed main() {
    int tc;
    cin >> tc;

    for (int c = 1; c <= tc; c++){
        cout << "Case " << c << ": ";
        int n;
        cin >> n;
    
        vector<vector<int>> a(2 * n, vector<int>(n + 1, 0));
        int cnt = 1;
        for (int i = 1; i <= 2 * n - 1; i++) {
            for (int j = 1; j <= cnt; j++) {
                cin >> a[i][j];
            }
            if (i < n) cnt++;
            else cnt--;
        }
        Solution sol;
        // cout << sol.tabulation(a, n) << endl;
        
        vector<vector<int>> dp(n * 2, vector<int>(n + 1, -1));
        cout << sol.TopDown(1, 1, n, dp, a) << endl;
    }
    return 0;
}