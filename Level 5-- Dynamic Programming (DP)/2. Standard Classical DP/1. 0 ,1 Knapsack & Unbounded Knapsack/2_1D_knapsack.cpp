#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout << '\n'
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> wt(n);
    for (auto &i : wt)
        cin >> i;
    vector<int> val(n);
    for (auto &i : val)
        cin >> i;

    vector<int> dp(w + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int cap = w; cap >= 0; cap--) {
            if (dp[cap] == -1)
                continue;
            if (cap + wt[i] <= w) {
                dp[cap + wt[i]] = max(dp[cap + wt[i]], dp[cap] + val[i]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}