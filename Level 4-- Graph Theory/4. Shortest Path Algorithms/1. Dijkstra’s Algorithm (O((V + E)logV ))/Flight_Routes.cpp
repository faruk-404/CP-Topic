#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); // one-way
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> cnt(n + 1, 0);
    vector<int> ans;

    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (cnt[u] >= k)
            continue; // এই node k বার হয়ে গেছে
        cnt[u]++;

        if (u == n)
            ans.push_back(d);

        for (auto [v, w] : adj[u]) {
            if (cnt[v] < k)
                pq.push({d + w, v});
        }
    }

    for (int x : ans)
        cout << x << ' ';
    cout << '\n';
    return 0;
}