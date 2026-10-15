#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout << '\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        //adj[v].push_back(make_pair(u, w));
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " --> ";
    //     for (auto [f, s] : adj[i])
    //         cout << f << "," << s << "   ";
    //     cout << '\n';
    // }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push(make_pair(0, 1));
    vector<int> dis(n + 2, LLONG_MAX);
    dis[1] = 0;
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (dis[node] != d)
            continue;
        for (auto [u, w] : adj[node]) {
            if (dis[u] > d + w) {
                dis[u] = d + w;
                pq.push(make_pair(d + w, u));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
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