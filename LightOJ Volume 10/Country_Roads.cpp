#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void Solve () {
    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int src;
    cin >> src;

    vector<int> dist(n, 1e15);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [wt, par] = pq.top();
        pq.pop();

        for (auto [nbr, Ewt] : adj[par]) {
            if (dist[nbr] > max(dist[par], Ewt)) {
                dist[nbr] = max(dist[par], Ewt);
                pq.push({dist[nbr], nbr});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == 1e15) {
            cout << "Impossible" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}
signed main() {
    int tc = 0;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cout << "Case " << i + 1 << ": \n";
        Solve();
    }
    return 0;
}