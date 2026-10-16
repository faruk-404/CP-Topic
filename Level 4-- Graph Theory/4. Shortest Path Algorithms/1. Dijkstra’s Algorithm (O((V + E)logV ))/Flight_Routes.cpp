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
    int n,m,k;cin>>n>>m>>k;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        // adj[v].emplace_back(u,w);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    priority_queue<int> dis[n+1];
    pq.push(make_pair(0,1));
    dis[1].push(0);
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if(d>dis[u].top()) continue;
        for(auto &[v,w]:adj[u]){
            if(dis[v].size()<k){
                dis[v].push(w+d);
                pq.push(make_pair(w+d,v));

            }
            else{
                if(dis[v].top()>(w+d)){
                    dis[v].pop();
                    dis[v].push(w+d);
                    pq.push(make_pair(w+d,v));

                }
            }
        }
    }
    vector<int> ans;
    while(!dis[n].empty()){
        ans.push_back(dis[n].top());
        dis[n].pop();
    }
    sort(all(ans));
    for(auto i:ans)cout<<i<<' ';
    cout<<'\n';


    
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

// #define int long long
// const int N = 1e5 + 5;
// vector<pair<int, int>> adj[N];

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m, k;
//     cin >> n >> m >> k;
//     for (int i = 0; i < m; i++) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         adj[a].push_back({b, c}); // one-way
//     }

//     priority_queue<pair<int, int>, vector<pair<int, int>>,
//                    greater<pair<int, int>>>
//         pq;
//     vector<int> cnt(n + 1, 0);
//     vector<int> ans;

//     pq.push({0, 1});
//     while (!pq.empty()) {
//         auto [d, u] = pq.top();
//         pq.pop();

//         if (cnt[u] >= k)
//             continue; // এই node k বার হয়ে গেছে
//         cnt[u]++;

//         if (u == n)
//             ans.push_back(d);

//         for (auto [v, w] : adj[u]) {
//             if (cnt[v] < k)
//                 pq.push({d + w, v});
//         }
//     }

//     for (int x : ans)
//         cout << x << ' ';
//     cout << '\n';
//     return 0;
// }