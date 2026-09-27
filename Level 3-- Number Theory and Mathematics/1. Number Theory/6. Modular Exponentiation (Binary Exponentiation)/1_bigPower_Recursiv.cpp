#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()

const int mod=1e9+7;
int bigmod(int a,int b){
    if(b==0)return 1LL;
    int tmp=bigmod(a,b/2)%mod;
    tmp=(tmp*tmp)%mod;
    if(b&1)tmp=(tmp*a)%mod;
    return tmp;
}


void solve(){

    int a,b;cin>>a>>b;  //a^b;
    cout<<bigmod(a,b)<<nl;
    
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){solve();}
    return 0;
}