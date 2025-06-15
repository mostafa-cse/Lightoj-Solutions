#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void UsingColoring () {
        int n;
        cin >> n;

        map<string, vector<string>> adj;
        map<string, int> vis;
        set<string> drinks;
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            drinks.insert(a);
            drinks.insert(b);
            vis[a] = vis[b] = 0;
            adj[a].push_back(b);
        }

        function<bool(const string&)> dfs = [&](const string &node) {
            vis[node] = 1; // visiting
            for (const string &nbr : adj[node]) {
                if (vis[nbr] == 0) {
                    if (dfs(nbr)) return true;
                } else if (vis[nbr] == 1) {
                    return true; // found a cycle
                }
            }
            vis[node] = 2; // visited
            return false;
        };

        bool cycle = 0;
        for (auto d : drinks) {
            if (vis[d] == 0) {
                cycle |= dfs(d);
            }
        }
        cout << (cycle ? "No" : "Yes") << endl;
    }
    void UsingDAG() {
        int n;
        cin >> n;
        map<string, vector<string>> adj;
        map<string, bool> visited, recStack;
        for (int i = 0; i < n; i++) {
            string u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            visited[u] = visited[v] = false; // initialize visited
            recStack[u] = recStack[v] = false; // initialize recStack
        }
        
        function<bool(const string&)> isCyclicUtil = [&](const string &node) {
            visited[node] = true; // visited
            recStack[node] = true; // visiting
            for (const string &neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor))
                return true;
            } else if (recStack[neighbor]) {
                return true; // cycle found
            }
            }
            recStack[node] = false; // done visiting
            return false;
        };

        for (auto it : adj) {
            if (!visited[it.first]) {
                if (isCyclicUtil(it.first))
                    return cout << "No" << endl, void();
            }
        }
        cout << "Yes" << endl;
    }

    void UsingTopologicalSort() {
        int n;
        cin >> n;
        map<string, vector<string>> adj;
        map<string, int> indegree;
        for (int i = 0; i < n; i++) {
            string u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            indegree[v]++;
            if (indegree.find(u) == indegree.end()) {
                indegree[u] = 0; // ensure all nodes are in indegree map
            }
        }

        queue<string> q;
        for (const auto &pair : indegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }

        int count = 0;
        while (!q.empty()) {
            string node = q.front();
            q.pop();
            count++;
            for (const string &neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        cout << (count == indegree.size() ? "Yes" : "No") << endl;
    }
};

void solve(){
    Solution sol;
    // sol.UsingDAG();
    // sol.UsingColoring();
    sol.UsingTopologicalSort(); 
}
int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}