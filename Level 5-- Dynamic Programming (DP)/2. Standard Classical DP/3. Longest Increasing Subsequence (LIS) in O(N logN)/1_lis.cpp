#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()

const int N=2e6+1;
vector<int> dp(N,1),path;
void prec(vector<int> &a){
    vector<int> pos(a.size()+3,-1);
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i]<a[j] && dp[j]<=dp[i]+1){
                dp[j]=dp[i]+1;
                pos[j]=i;
            }
        }
    }
    int idx=max_element(dp.begin(),dp.begin()+a.size())-dp.begin();
    while(idx!=-1){
        path.push_back(a[idx]);
        idx=pos[idx];
    }
    reverse(path.begin(),path.end());
}

void solve(){

    int n;cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    prec(a);
    cout<<path.size()<<nl;
    for(auto i:path)cout<<i<<' ';
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