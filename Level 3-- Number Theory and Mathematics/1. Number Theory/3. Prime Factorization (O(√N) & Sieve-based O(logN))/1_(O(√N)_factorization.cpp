#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()


vector<int> factorization(int n){
    vector<int> prime;
    for(int i=2;i*i<=n;i++){
        if(n%i!=0)continue;
        prime.push_back(i);
        while(n%i==0)n/=i;
    }
    if(n>1)prime.push_back(n);
    return prime;
}

map<int,int> factor(int n){
    map<int,int> prime;
    for(int i=2;i*i<=n;i++){
        if(n%i!=0) continue;
        int cnt=0;
        while(n%i==0){
            cnt++;
            n/=i;
        }
        prime[i]=cnt;
    }
    if(n>1)prime[n]=1;
    return prime;
}

void solve(){
    int n;cin>>n;
    map<int,int> prime;
    prime=factor(n);
    for(auto [x,y]:prime)cout<<x<<' '<<y<<nl;
    
    vector<int> prime1=factorization(n);
    for(auto i:prime1)cout<<i<<" ";nf;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}