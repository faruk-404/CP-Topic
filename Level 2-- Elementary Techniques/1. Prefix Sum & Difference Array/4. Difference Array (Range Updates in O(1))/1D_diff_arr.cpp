#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    vector<int> diff(n+1,0);
    int q;cin>>q;
    while(q--){
        int l, r, val; cin >> l >> r >> val;
        l--,r--;
        diff[l]+=val;
        diff[r+1]+=val;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=diff[i];
        a[i]+=sum;        
    }
    for(auto &i:a)cout<<i<<' ';
    cout<<'\n';
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}