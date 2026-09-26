#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long
#define int long long

const int N=1e6+5, p=137, mod=998244353;
vector<int> pw(N), pre(N), ipw(N);

int bigmod(int a,int b){
    if(b==0) return 1LL;
    int tmp=bigmod(a,b/2);
    tmp=(tmp*tmp)%mod;
    if(b&1) tmp=(tmp*a)%mod;
    return tmp;
}

void prec(){
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=(pw[i-1]*p)%mod;

    ipw[0]=1;
    int ip=bigmod(p,mod-2);
    for(int i=1;i<N;i++) ipw[i]=(ipw[i-1]*ip)%mod;
}

void build(string &s){
    pre[0]=(s[0]*pw[0])%mod;
    for(int i=1;i<(int)s.size();i++){
        pre[i]=(pre[i-1]+(s[i]*pw[i])%mod)%mod;
    }
}

int get_hash(string &s){
    int hs=0;
    for(int i=0;i<(int)s.size();i++){
        hs=(hs+(s[i]*pw[i])%mod)%mod;
    }
    return hs;
}

int rangeLRHash(int l,int r){
    int hs=pre[r];
    if(l==0) return hs;
    hs=(hs-pre[l-1]+mod)%mod;
    hs=(hs*ipw[l])%mod;
    return hs;
}

void solve(){
    string s; cin>>s;
    string x; cin>>x;

    build(s);
    int xx=get_hash(x);
    int cnt=0;

    for(int i=0; i + (int)x.size() - 1 < (int)s.size(); i++){
        if(xx == rangeLRHash(i, i+(int)x.size()-1)) cnt++;
    }
    cout << cnt << nl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prec();
    int t=1;
    while(t--) solve();
    return 0;
}