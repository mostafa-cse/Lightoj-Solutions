#include <bits/stdc++.h>
#define int long long
using namespace std;
int col, row;
string grid[21];
bool vis[21][21];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dfs(int i, int j) {
    int ans = 0;
    for (int d = 0; d < 4; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];
        if (ni < row and nj < col and ni >= 0 and nj >= 0 and vis[ni][nj] == false and grid[ni][nj] == '.') {
            vis[ni][nj] = true;
            ans = 1 + dfs(ni, nj);
        }
    }
    return ans;
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(m, vector<char>(n));
    int si = -1, se = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == '@') {
                si = i, se = j;
            }
        }
    }
    vector<vector<int>> vis(m, vector<int>(n, 0));
    function<int(int, int)> dfs = [&](int i, int j) -> int {
        if (i < 0 or j < 0 or i >= m or j >= n or vis[i][j] or a[i][j] == '#') return 0;
        vis[i][j] = 1;
        return 1 + dfs(i + 1, j) + dfs(i, j + 1) + dfs(i - 1, j) + dfs(i, j - 1);
    };
    cout << dfs(si, se) << endl;
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