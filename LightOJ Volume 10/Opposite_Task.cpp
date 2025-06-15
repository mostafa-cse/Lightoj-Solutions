#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int a;
    cin >> a;

    if (a == 20) {
        cout << 10 << ' ' << 10 << endl;
    } else {
        cout << a % 10 << ' ' << a - (a % 10) << endl;
    }
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}