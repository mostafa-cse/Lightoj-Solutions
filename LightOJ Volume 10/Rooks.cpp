#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int ncr[1000][1000];
int nCr(int n, int r){
    ncr[0][0] = 1;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= r; j++){
            if (i == j){
                ncr[i][j] = 1;
            }else if (i < j){
                ncr[i][j] = 0;
                break;
            }else{
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]);
            }
        }
    }
    return ncr[n][r];
}
void Solve () {
    int n, k;
    cin >> n >> k;

    int a = nCr(n, k);
    int fact = 1;
    for (int i = 1l; i <= k; i++) {
        fact *= i;
    }
    cout << a * a * fact << endl;
}
void Solve () {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for (int i = n - k + 1, deno = 1; i <= n; i++, deno++) {
        ans *= i;
        ans /= deno;
    }
    ans *= ans;
    for (int i = 1; i <= k; i++) {
        ans *= i;
    }
    cout << ans << endl;
}
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