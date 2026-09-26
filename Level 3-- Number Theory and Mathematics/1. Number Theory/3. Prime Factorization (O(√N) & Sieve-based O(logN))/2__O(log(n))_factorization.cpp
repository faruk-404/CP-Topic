#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

const int  N=1e6+5;
vector<int> spf(N),primef(N);
void SPF(){
    for(int i=2;i<N;i++)spf[i]=i;
    for(int i=2;i<N;i++){
        if(spf[i]!=i)continue;
        for(int j=i;j<N;j+=i){
            if(spf[j]==j)spf[j]=i;
        }
    }
}
void factorizaion(vector<int> &a){
    for(auto n:a){
        if(n<2)continue;
        while(n>1){
            primef[spf[n]]++;
            n/=spf[n];
        }
    }
}

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    factorizaion(a);
    for(int i=0;i<N;i++){
        if(primef[i]>0)cout<<i<<" "<<primef[i]<<nl;
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    SPF();
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}