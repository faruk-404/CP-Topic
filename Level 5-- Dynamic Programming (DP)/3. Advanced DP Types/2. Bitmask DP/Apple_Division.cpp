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
    int n;cin>>n;
    vector<int>a(n);
    for(auto &i:a)cin>>i;
    int ans=LLONG_MAX;
    int tsum=accumulate(a.begin(),a.end(),0LL);
    for(int mask=1;mask<(1<<n);mask++){
        int sum=0;
        for(int i=0;i<n;i++) if((mask>>i)&1)sum+=a[i];
        ans=min(ans,abs(tsum-(2*sum)));        
    }
    cout<<ans<<nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}