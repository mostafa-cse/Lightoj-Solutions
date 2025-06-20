#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int M = 5e6;
vector<int> phi(M + 1);
auto pre = []() {
    iota(phi.begin(), phi.end(), 0);
    phi[1] = 0;
    for (int i = 2; i <= M; i++) {
        if (phi[i] != i) continue;
        for (int j = i; j <= M; j += i) {
            phi[j] -= phi[j] / i;
        }
    }
    for (int i = 2; i <= M; i++) {
        phi[i] = phi[i] * phi[i] + phi[i - 1];
    }
    return "Precalculate Phi";
}();
void solve() {
    int a, b;
    cin >> a >> b;
    cout << phi[b] - phi[a - 1] << endl;
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