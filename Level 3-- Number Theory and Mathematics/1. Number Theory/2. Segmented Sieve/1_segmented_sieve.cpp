#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout << '\n'
#define ll long long
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()

vector<int> sieve(int limit) {
    vector<bool> isComposite(limit + 1, false);
    vector<int> prime;
    for (int i = 2; i * i <= limit; i++) {
        if (isComposite[i])
            continue;
        for (int j = i * i; j < limit; j += i)
            isComposite[j] = true;
    }
    if (limit >= 2)
        prime.push_back(2);
    for (int i = 3; i <= limit; i += 2)
        if (!isComposite[i])
            prime.push_back(i);
    return prime;
}
vector<int> segmentedSieve(int L, int R) {
    int limit = (int)sqrt((double)R);
    vector<int> prime = sieve(limit);
    int sz = R - L + 1;
    vector<bool> isComposite(sz, false);
    if (L == 0) {
        if (sz > 0)
            isComposite[0] = true;
        if (sz > 1)
            isComposite[1] = true;
    }
    if (L == 1)
        isComposite[0] = true;
    for (int p : prime) {
        int start = max(p * p, ((L + p - 1) / p) * p);
        for (int j = start; j <= R; j += p)
            isComposite[j - L] = true;
    }
    vector<int> primeInRange;
    for (int i = 0; i < sz; i++) {
        if (isComposite[i])
            continue;
        primeInRange.push_back(i + L);
    }
    return primeInRange;
}

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> p = segmentedSieve(l, r);
    for (auto i : p)
        cout << i << ' ';
    cout << '\n';
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}