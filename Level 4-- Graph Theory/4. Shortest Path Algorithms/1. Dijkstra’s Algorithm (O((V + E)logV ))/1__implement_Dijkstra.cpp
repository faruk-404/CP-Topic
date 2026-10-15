#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout << '\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
const int N = 1e5;
vector<pair<int, int>> adj[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> dis(n + 1, (int)1e18);
    vector<int> par(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (dis[node] != d)
            continue;
        for (auto [u, w] : adj[node]) {
            if (dis[u] > d + w) {
                dis[u] = d + w;
                pq.push({dis[u], u});
                par[u] = node;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    cout << nl;
    vector<int> path;
    int cur = n;
    while (cur != -1) {
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(all(path));
    for (auto i : path)
        cout << i << " ";
    cout << '\n';
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}