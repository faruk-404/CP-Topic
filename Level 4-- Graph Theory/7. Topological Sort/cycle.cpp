#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout << '\n'
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
const int N = 3e5 + 5;

vector<int> adj[N];
vector<ll> mark(N, 0), order;  // 0=unvisited 1=in stack 2=done
bool cyc = false;
void dfs(ll u) {
    if (mark[u] == 2) return;
    if (mark[u] == 1) {
        cyc = true;
        return;
    }
    mark[u] = 1;
    for (ll v : adj[u]) dfs(v);
    mark[u] = 2;
    order.push_back(u);
}
void solve() {
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}