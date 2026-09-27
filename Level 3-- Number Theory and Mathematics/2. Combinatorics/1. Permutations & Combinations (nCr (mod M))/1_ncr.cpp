#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()

const int N=2e6+5,mod=1e9+7;
vector<int> fact(N,1),ifact(N,1);
void prec(){
    for(int i=2;i<N;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
}
int bigmod(int a,int b){
    if(b==0)return 1LL;
    int tmp=bigmod(a,b/2)%mod;
    tmp=(tmp*tmp)%mod;
    if(b&1)tmp=(tmp*a)%mod;
    return tmp;
}
int nCr(int n,int r){
    if(r<0 || r>n || n<0) return 0;
    return (fact[n]*bigmod((fact[r]*fact[n-r])%mod,mod-2))%mod;
}

void solve(){
    int n,r;cin>>n>>r;
    cout<<nCr(n,r)<<nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prec();
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}