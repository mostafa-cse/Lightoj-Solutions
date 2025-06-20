#include<bits/stdc++.h>
#define int long long
using namespace std;
int sq(int x) {
    return x * x;
}
void Solve() {
    int n;
    cin >> n;

    int R_C = ceil(sqrtl(n));
    int Row, Col;
    if (R_C & 1) {
        Row = sq(R_C);
        Col = sq(R_C - 1) + 1;
        if (Row - n < n - Col) {
            cout << Row - n + 1 << " " << R_C;
        } else {
            cout << R_C << " " << n - Col + 1;
        }
    } else {
        Row = sq(R_C - 1) + 1;
        Col = sq(R_C);

        if (n - Row < Col - n) {
            cout << n - Row + 1 << " " << R_C;
        } else {
            cout << R_C << " " << Col - n + 1;
        }
    }
}
int32_t main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        if (i != 1) {
            cout << endl;
        }
        cout << "Case "<< i << ": ";
        Solve();
    }
    return 0;
}