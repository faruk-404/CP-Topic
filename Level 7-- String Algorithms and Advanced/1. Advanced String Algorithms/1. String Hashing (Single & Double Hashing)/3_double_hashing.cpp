#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()


const int N=1e6+5, p1=137, p2=277, mod1=998244353, mod2=1e9+7;
vector<pair<int,int>> pw(N), pre(N), ipw(N);

int bigmod(int a,int b,int mod){
    if(b==0) return 1LL;
    int tmp=bigmod(a,b/2,mod);
    tmp=(tmp*tmp)%mod;
    if(b&1) tmp=(tmp*a)%mod;
    return tmp;
}

void prec(){
    pw[0]={1,1};
    for(int i=1;i<N;i++){
        pw[i].first=(pw[i-1].first*p1)%mod1;
        pw[i].second=(pw[i-1].second*p2)%mod2;
    }

    ipw[0]={1,1};
    int ip1=bigmod(p1,mod1-2,mod1);
    int ip2=bigmod(p2,mod2-2,mod2);
    for(int i=1;i<N;i++){
        ipw[i].first=(ipw[i-1].first*ip1)%mod1;
        ipw[i].second=(ipw[i-1].second*ip2)%mod2;
    }
}

void build(string &s){
    pre[0].first=(s[0]*pw[0].first)%mod1;
    pre[0].second=(s[0]*pw[0].second)%mod2;
    for(int i=1;i<(int)s.size();i++){
        pre[i].first=(pre[i-1].first+(s[i]*pw[i].first)%mod1)%mod1;
        pre[i].second=(pre[i-1].second+(s[1]*pw[i].second)%mod2)%mod2;
    }
}

pair<int,int> get_hash(string &s){
    pair<int,int> hs={0,0};
    for(int i=0;i<(int)s.size();i++){
        hs.first=(hs.first+(s[i]*pw[i].first)%mod1)%mod1;
        hs.second=(hs.second+(s[i]*pw[i].second)%mod2)%mod2;
    }
    return hs;
}

pair<int,int> rangeLRHash(int l,int r){
    pair<int,int> hs=pre[r];
    if(l==0) return hs;

    hs.first=(hs.first-pre[l-1].first+mod1)%mod1;
    hs.second=(hs.second-pre[l-1].second+mod2)%mod2;
    
    hs.first=(hs.first*ipw[l].first)%mod1;
    hs.second=(hs.second*ipw[l].second)%mod2;
    return hs;
}

void solve(){
    string s; cin>>s;
    string x; cin>>x;

    build(s);
    pair<int,int> xx=get_hash(x);
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
    // cin>>t;
    while(t--){solve();}
    return 0;
}