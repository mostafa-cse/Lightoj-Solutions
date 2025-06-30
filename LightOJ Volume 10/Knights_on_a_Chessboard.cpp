#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    
    if (n > m) swap(n, m);

    int ans = 0;
    if (n == 1) {
        ans = max(m, n);
    } else if (n == 2) {
        ans = (m >> 2) << 2;
        if (m % 4 == 1) ans += 2;
        else if (m % 4 >= 2) ans += 4;
    } else {
        /*
            . x . x . x . x . x
            x . x . x . x . x .
            . x . x . x . x . x
            x . x . x . x . x . 
        */
        ans = (m * n + 1) >> 1;
    }
    cout << ans << endl;
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