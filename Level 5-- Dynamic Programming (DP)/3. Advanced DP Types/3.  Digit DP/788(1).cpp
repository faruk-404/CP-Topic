#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout << '\n'
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
const int N = 3e5 + 5;
string s;
int memo[6][2][2];
int go(int pos, bool changed, bool tight) {
    if (pos == s.size()) return changed;
    int& r = memo[pos][changed][tight];
    if (r != -1) return r;
    r = 0;
    int lim = tight ? s[pos] - '0' : 9;
    for (int d = 0; d <= lim; d++) {
        if (d == 3 || d == 4 || d == 7) continue;
        bool nc = (changed || d == 2 || d == 5 || d == 6 || d == 9);
        r += go(pos + 1, nc, tight && d == lim);
    }
    return r;
}
int rotatedDigit(int n) {
    s = to_string(n);
    memset(memo, -1, sizeof(memo));
    return go(0, false, true);
}

void solve() {
    int n;
    cin >> n;
    cout << rotatedDigit(n) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}