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
    vector<tuple<int,int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w,c;cin>>u>>v>>w>>c;
        adj[v].emplace_back(u,w,c);
        adj[u].emplace_back(v,w,c);
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    pq.push(make_tuple(0,1,0));
    pq.push(make_tuple(0,1,1));
    int dis[2][n+1];
    for(int i=0;i<2;i++){
        for(int j=0;j<=n;j++) dis[i][j]=LLONG_MAX;
    }
    dis[0][1]=0;
    dis[1][1]=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int d,u,c;
        tie(d,u,c)=p;
        if(dis[c][u]!=d)continue;
        for(auto &[v,w,cl]:adj[u]){
            if(cl!=c && dis[cl][v]> d+w){
                dis[cl][v]=d+w;
                pq.push(make_tuple(d+w,v,cl));
            }
        }
    }
    int dise;cin>>dise;
    cout<<min(dis[0][n],dis[1][n])<<nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}// // starting with the name of almighty ALLAH
// //  Practice is the only shortcut to improve
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5;
// #define tii tuple<int, int, int>
// vector<tii> adj[N];
// int main() {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++) {
//         int u, v, w, c;
//         cin >> u >> v >> w >> c;
//         adj[u].push_back(make_tuple(v, w, c));
//         adj[v].push_back(make_tuple(u, w, c));
//     }
//     priority_queue<tii, vector<tii>, greater<tii>> pq;
//     int dis[2][n + 1];
//     for (int i = 0; i < 2; i++) {
//         for (int j = 1; j <= n; j++) {
//             dis[i][j] = INT_MAX;
//         }
//     }
//     pq.push(make_tuple(0, 1, 0));
//     pq.push(make_tuple(0, 1, 1));
//     dis[0][1] = 0;
//     dis[1][1] = 0;
//     while (!pq.empty()) {
//         tii f = pq.top();
//         pq.pop();
//         int d, u, c;
//         tie(d, u, c) = f;
//         if (d != dis[c][u])
//             continue;
//         for (auto &[v, w, cl] : adj[u]) {
//             if (c == cl)
//                 continue;
//             int nd = d + w;
//             if (nd < dis[cl][v]) {
//                 dis[cl][v] = nd;
//                 pq.push(make_tuple(nd, v, cl));
//             }
//         }
//     }
//     int des;
//     cin >> des;
//     cout << min(dis[0][des], dis[1][des]) << endl;
//     return 0;
// }