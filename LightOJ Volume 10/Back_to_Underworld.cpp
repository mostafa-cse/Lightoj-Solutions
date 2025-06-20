#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;

    vector<int> adj[20005];
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(20005, 0);
    int a = 0, b = 0;
    function<void(int, int)> dfs = [&](int u, int clr) -> void
    {
        a += clr;
        b += !clr;
        vis[u] = 1;
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                dfs(v, clr ^ 1);
            }
        }
    };

    int ans = 0;
    for (int i = 1; i <= 20000; i++)
    {
        if (!vis[i] and !adj[i].empty())
        {
            a = 0, b = 0;
            dfs(i, 0);
            ans += max(a, b);
        }
    }
    cout << ans << endl;
}
void Solve_BFS()
{
    int n;
    cin >> n;

    vector<int> adj[20005];
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    vector<int> vis(20005, 0);
    for (int i = 1; i <= 20000; i++)
    {
        if (!vis[i] && !adj[i].empty())
        {
            queue<pair<int, int>> q;
            vis[i] = 1; 
            q.push({i, 0});
            int a = 0, b = 0;
            while (!q.empty())
            {
                auto [U, clr] = q.front();
                a += clr;
                b += !clr;
                for (int V : adj[U])
                {
                    if (!vis[V])
                    {
                        vis[V] = 1; 
                        q.push({V, clr ^ 1});
                    }
                }
                q.pop();
            }
            ans += max(a, b);
        }
    }
    cout << ans << endl;
}
signed main()
{
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        Solve_BFS();
    }
    return 0;
}