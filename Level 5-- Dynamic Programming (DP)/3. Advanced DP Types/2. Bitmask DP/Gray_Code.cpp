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
    for(int i=0;i<(1<<n);i++){
        int c=(i^(i>>1));
        for(int j=n-1;j>=0;j--){
            if((c>>j)&1)cout<<1;
            else cout<<0;
        }
        cout<<'\n';
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