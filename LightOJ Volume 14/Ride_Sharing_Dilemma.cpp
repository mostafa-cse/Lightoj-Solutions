#include <bits/stdc++.h>
#define int long long
using namespace std;
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) : parent(n + 1), rank(n + 1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return false;
        if (rank[ra] < rank[rb]) swap(ra, rb);

        parent[rb] = ra;
        if (rank[ra] == rank[rb]) {
            ++rank[ra];
        }
        return true;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<array<int, 3>> edge(m);
    for (auto &[x, y, z] : edge) {
        cin >> x >> y >> z;
    }

    function<int(int idx)> cost = [&](int idx) -> int {
        vector<array<int, 3>> a;
        for (int i = 0; i < m; i++) {
            if (i == idx) continue;
            a.push_back({edge[i][0], edge[i][1], edge[i][2]});
        }
        sort(a.begin(), a.end(), [&](array<int, 3>&x, array<int, 3>&y){
            return x[2] < y[2];
        });

        int ans = 0;
        DSU ds(n);
        for (int i = 0; i < a.size(); i++) {
            if (ds.unite(a[i][0], a[i][1])) {
                ans += a[i][2];
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (ds.find(i) == i) cnt++;
            if (cnt == 2) return -1;
        }
        return ans;
    };

    for (int i = 0; i < m; i++) {
        int ans = cost(i);
        if (ans == -1) {
            cout << "impossible" << endl;
        } else {
            cout << ans + 1 << endl;
        }
    }
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}