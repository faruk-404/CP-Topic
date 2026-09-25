#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

int knapsack2D(int w,vector<int> wt,vector<int> val,int n){
    vector<vector<int>> dp(n+1, vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        for(int cap=0;cap<=w ;cap++){
            dp[i][cap]=dp[i-1][cap];
            if(wt[i-1]<=cap){
                dp[i][cap]=max(dp[i][cap],dp[i-1][cap-wt[i-1]]+val[i-1]);
            }
        }
    }
    return dp[n][w];
}

void solve(){
    int n,w;cin>>n>>w;
    vector<int> wt(n);
    for(auto &i:wt)cin>>i;
    vector<int> val(n);
    for(auto &i:val)cin>>i;
    cout<<knapsack2D(w,wt,val,n)<<nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}