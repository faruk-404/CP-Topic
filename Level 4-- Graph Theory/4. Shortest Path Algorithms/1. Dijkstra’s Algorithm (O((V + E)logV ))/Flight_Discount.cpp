#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()

void solve(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w,c;cin>>u>>v>>w;
        // adj[v].emplace_back(u,w,c);
        adj[u].emplace_back(v,w);
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    pq.push(make_tuple(0,1,0));
    // pq.push(make_tuple(0,1,1));
    int dis[2][n+1];
    for(int i=0;i<2;i++){
        for(int j=0;j<=n;j++) dis[i][j]=LLONG_MAX;
    }
    dis[0][1]=0;
    // dis[1][1]=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int d,u,tu;
        tie(d,u,tu)=p;
        if(dis[tu][u]!=d)continue;
        for(auto &[v,w]:adj[u]){
            if(dis[tu][v]> d+w){
                dis[tu][v]=d+w;
                pq.push(make_tuple(d+w,v,tu));
            }
            if(tu==0 && dis[1][v]>(d+w/2)){
                dis[1][v]=d+w/2;
                pq.push(make_tuple(d+w/2,v,1));
                
            }
        }
    }
    cout<<dis[1][n]<<nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
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

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<pair<int, int>> adj[n + 1];
//     int a[n + 1][n + 1];
//     for (auto &i : a)
//         for (auto &j : i)
//             j = LLONG_MAX;
//     for (int i = 0; i < m; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         a[u][v] = min(w, a[u][v]);
//         a[v][u] = min(w, a[v][u]);
//         adj[u].push_back(make_pair(v, w));
//         adj[v].push_back(make_pair(u, w));
//     }
//     vector<int> dis(n + 1, (int)1e18);
//     vector<int> par(n + 1, -1);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//     dis[1] = 0;
//     pq.push({0, 1});
//     while (!pq.empty()) {
//         auto [d, node] = pq.top();
//         pq.pop();
//         if (dis[node] != d)
//             continue;
//         for (auto [u, w] : adj[node]) {
//             if (dis[u] > d + w) {
//                 dis[u] = d + w;
//                 pq.push({dis[u], u});
//                 par[u] = node;
//             }
//         }
//     }
//     // for (int i = 1; i <= n; i++)
//     //     cout << dis[i] << ' ';
//     // cout << nl;
//     vector<int> path;
//     int cur = n;
//     while (cur != -1) {
//         path.push_back(cur);
//         cur = par[cur];
//     }
//     int ans = dis[n];
//     int mx = dis[n];
//     reverse(all(path));
//     for (int i = 1; i < path.size(); i++) {
//         ans = min((int)(mx - ceil((double)a[path[i - 1]][path[i]] / 2.0)), ans);
//     }
//     cout << ans << nl;
// }
// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t = 1;
//     // cin>>t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }