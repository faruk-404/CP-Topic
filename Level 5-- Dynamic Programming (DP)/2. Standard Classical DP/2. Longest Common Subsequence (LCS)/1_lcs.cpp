#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()

string lcs = "";
void prec(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<pair<int, int>>> pos(n + 1, vector<pair<int, int>>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = 1 + ((i && j) ? dp[i - 1][j - 1] : 0);
                pos[i][j] = {i - 1, j - 1};
            } else {
                int tm1 = i ? dp[i - 1][j] : 0;
                int tm2 = j ? dp[i][j - 1] : 0;
                if (tm1 > tm2) {
                    dp[i][j] = tm1;
                    pos[i][j] = {i - 1, j};
                } else {
                    dp[i][j] = tm2;
                    pos[i][j] = {i, j - 1};
                }
            }
        }
    }
    pair<int, int> idx = {n - 1, m - 1};
    while (idx.first >= 0 && idx.second >= 0) {
        if (s[idx.first] == t[idx.second]) {
            lcs.push_back(s[idx.first]);
        }
        idx = pos[idx.first][idx.second];
    }
    reverse(lcs.begin(), lcs.end());
}


void solve(){
    string s,t;cin>>s>>t;
    prec(s,t);
    cout<<lcs.size()<<nl;
    cout<<lcs<<nl;
    
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}