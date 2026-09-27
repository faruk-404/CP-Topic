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
    int result=1;
    a%=mod;
    while(b>0){
        if(b&1) result=(result*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return result;
}
void solve(){
    int a,b;cin>>a>>b;
    cout<<bigmod(a,b)<<nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}