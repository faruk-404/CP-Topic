// https://leetcode.com/problems/rotated-digits/description/
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout << '\n'
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
const int N = 3e5 + 5;

int rotatedDigits(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        bool valid = true, changed = false;
        for (char c : s) {
            if (c == '3' || c == '4' || c == '7') {
                valid = false;
                break;
            }
            if (c == '2' || c == '5' || c == '6' || c == '9') changed = true;
        }
        if (valid && changed) ans++;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    cout << rotatedDigits(n) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}