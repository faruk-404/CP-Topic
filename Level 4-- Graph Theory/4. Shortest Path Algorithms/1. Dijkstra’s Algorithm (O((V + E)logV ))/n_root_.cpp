#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    vector<set<int>> dis(n + 1);
    dis[1].insert(0);

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int u : adj[p]) {
            for (int d : dis[p])
                dis[u].insert(d + 1);
            if (--indeg[u] == 0) q.push(u);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " --> ";
        for (int d : dis[i]) cout << d << ' ';
        cout << nl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}// #include <bits/stdc++.h>
// using namespace std;

// #define nl '\n'
// #define nf cout << '\n'
// #define ll long long
// #define int long long
// #define cy cout << "YES\n"
// #define cn cout << "NO\n"
// #define all(v) v.begin(), v.end()
// const int N = 1e5 + 5;
// vector<int> adj[N];

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         // adj[v].push_back(u);
//     }
    
//     vector<int> dis[n+2];
//     vector<bool> vis(n + 1, false);
//     dis[1].push_back(0);
//     vis[1] = true;
//     queue<int> q;
//     q.push(1);

//     while (!q.empty()) {
//         int p = q.front();
//         q.pop();
//         for (auto u : adj[p]) {
//             // if (vis[u])
//             //     continue;
//             for (auto d : dis[p])
//                 dis[u].push_back(d + 1);
//             q.push(u);
//             // vis[u] = true;
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         cout<<i<<" --> ";
//         for (auto d : dis[i])
//             cout << d << " ";
//         cout << '\n';
//     }
//     for(int i=1;i<=n;i++){
//         cout<<i<<" --> {";
//         for(auto u:adj[i])cout<<u<<",";
//         cout<<"}\n";
//     }
//     cy;
// }
// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t = 1;
//     // cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }