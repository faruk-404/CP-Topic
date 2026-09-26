#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout << '\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()

const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const int N = 1e6 + 9;
pair<int, int> pw[N], ipw[N];
vector<pair<int, int>> pref(N);

int bigmod(int a, int b, int mod) {
    if (b == 0)
        return 1LL;
    int tmp = bigmod(a, b / 2, mod) % mod;
    tmp = (tmp * tmp) % mod;
    if (b & 1)
        tmp = (tmp * a) % mod;
    return tmp;
}

void prec() { // O(n)
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    int ip1 = bigmod(p1, mod1 - 2, mod1);
    int ip2 = bigmod(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

pair<int, int> string_hash(string s) { // O(n)
    int n = s.size();
    pair<int, int> hs({0, 0});
    for (int i = 0; i < n; i++) {
        hs.first = (hs.first % mod1 + 1LL * s[i] * pw[i].first % mod1) % mod1;
        hs.second =
            (hs.second % mod2 + 1LL * s[i] * pw[i].second % mod2) % mod2;
    }
    return hs;
}

void build(string s) { // O(n)
    int n = s.size();
    for (int i = 0; i < n; i++) {
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if (i)
            pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if (i)
            pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
}

pair<int, int> get_hash(int i, int j) { // O(1)
    pair<int, int> hs({0, 0});
    hs.first = pref[j].first;
    if (i)
        hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;

    hs.second = pref[j].second;
    if (i)
        hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;

    return hs;
}

void solve(){
    string s; cin>>s;
    string x; cin>>x;

    build(s);
    pair<int,int> xx=string_hash(x);
    int cnt=0;

    for(int i=0; i + (int)x.size() - 1 < (int)s.size(); i++){
        if(xx == get_hash(i, i+(int)x.size()-1)) cnt++;
    }
    cout << cnt << nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prec();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}