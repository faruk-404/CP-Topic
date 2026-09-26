#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define int long long
#define all(v) v.begin(), v.end()

vector<int> sieve(int limit) {
    vector<bool> isComposite(limit + 1, false);
    vector<int> primes;
    
    for (int i = 2; i * i <= limit; i++){
        if(isComposite[i]) continue;
        for(int j = i*i; j <= limit; j += i) isComposite[j] = true;
    }
    for (int i = 2; i <= limit; i++){
        if(!isComposite[i]) primes.push_back(i);
    }
    return primes;
}

vector<int> segmentSieve(int L, int R){
    if(L > R) return {};

    int limit = (int)sqrtl((long double)R);
    while(limit*limit > R) limit--;
    while((limit+1)*(limit+1) <= R) limit++;

    vector<int> basePrimes = sieve(limit);

    int sz = R - L + 1;
    vector<bool> isComposite(sz, false);

    if(L == 0){
        if(sz > 0) isComposite[0] = true;
        if(sz > 1) isComposite[1] = true;
    }
    if(L == 1) isComposite[0] = true;

    for(int p : basePrimes){
        int start = max(p*p, ((L + p - 1) / p) * p);
        for(int j = start; j <= R; j += p)
            isComposite[j - L] = true;
    }

    vector<int> primeInRange;
    for(int i = 0; i < sz; i++){
        if(!isComposite[i]) primeInRange.push_back(i + L);
    }
    return primeInRange;
}

void solve() {
    int l, r; cin >> l >> r;
    vector<int> p = segmentSieve(l, r);
    for(auto i : p) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}