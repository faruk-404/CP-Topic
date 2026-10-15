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
    int n,m,q;cin>>n>>m>>q;
    vector<pair<int,int>> adj[n+3];
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[v].push_back(make_pair(u,w));
        adj[u].push_back(make_pair(v,w));
    }
    int dist[n+1][n+1];
    for(int scr=1;scr<=n;scr++){
        vector<int> dis(n+1,LLONG_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0,scr));
        dis[scr]=0;
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(dis[node]!=d)continue;
            for(auto [u,w]:adj[node]){
                if(dis[u]> d+w){
                    dis[u]=d+w;
                    pq.push(make_pair(d+w,u));
                }
            }
        }
        for(int i=1;i<=n;i++){
            dist[scr][i]=(dis[i]==LLONG_MAX)?-1:dis[i];
        }}
    while(q--){
        int l,r;cin>>l>>r;
        cout<<dist[l][r]<<nl;
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}