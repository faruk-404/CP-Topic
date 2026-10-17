#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
const int N=2e5+1;
vector<int> adj[N];
int dis=0,dnode=-1;
void dfs(int node,int parent,int dist){
    if(dist>dis){
        dis=dist;
        dnode=node;
    }
    for(auto &u:adj[node]){
        if(u==parent)continue;
        dfs(u,node,dist+1);
    }
}
void solve(){
    int n,m;cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1,0);
    dfs(dnode,-1,0);
    cout<<dis<<nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}