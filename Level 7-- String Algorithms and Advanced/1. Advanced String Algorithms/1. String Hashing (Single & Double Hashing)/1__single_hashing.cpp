#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()

const int N=1e6+5,P=137,mod=1e9+7;
vector<int> pw(N);

void prec(){
    pw[0]=1;
    for(int i=1;i<N;i++){
        pw[i]=(pw[i-1]*P)%mod;
    }
}

int get_hash(string &s){
    int hs=0;
    for(int i=0;i<s.size();i++){
        hs=(hs+(s[i]*pw[i])%mod)%mod;
    }
    return hs;
}

void solve(){
    string a,b; cin>>a>>b;
    if(get_hash(a)==get_hash(b)){
        cout<<get_hash(a)<<' '<<get_hash(b)<<nl;
        cout<<"Same String\n";
    }else {
        cout<<get_hash(a)<<' '<<get_hash(b)<<nl;
        cout<<"Not Same\n";
    }
    
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