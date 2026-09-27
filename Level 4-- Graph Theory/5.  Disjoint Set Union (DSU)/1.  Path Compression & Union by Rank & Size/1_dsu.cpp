#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()

struct DSU{
    int c;
    vector<int> par,rnk,siz;
    DSU(int n):par(n+1),rnk(n+1),siz(n+1,1){
        c=n;
        for(int i=1;i<=n;i++) par[i]=i;
    }
    int find(int i){
        if(i==par[i])return i;
        return par[i]=find(par[i]);
    }

    bool same(int u,int v){
        return find(u)==find(v);
    }
    int getsize(int u){
        return siz[find(u)];
    }
    int cnt(){
        return c;
    }
    void merge(int u,int v){
        u=find(u),v=find(v);
        if(u==v)return;
        else c--;
        if(rnk[u]>rnk[v])swap(u,v);
        else if(rnk[u]==rnk[v]) rnk[v]++;
        par[u]=v;
        siz[v]+=siz[u];
    }
};

void solve(){
    int n,m;cin>>n>>m;
    DSU d(n);
    for(int i=1;i<=m;i++){
        string s;cin>>s;
        int u,v;cin>>u>>v;
        if(s=="union"){
            d.merge(u,v);
        }else if(d.same(u,v))cout<<"YES\n";
        else cout<<"NO\n";

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