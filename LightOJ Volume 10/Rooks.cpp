#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void Solve () {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for (int i = n - k + 1, deno = 1; i <= n; i++, deno++) {
        ans *= i * i;
        ans /= deno;
    }
    cout << ans << endl;
}
signed main() {
    int tc = 0;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}