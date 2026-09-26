#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define int long long
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
const int N = 1e7 + 5;
bitset<N / 2> isComposite;   // index i → number (2*i + 1)
vector<int> primes;
void sieve() {
    for (int i = 1; (ll)(2 * i + 1) * (2 * i + 1) < N; i++) {
        if (!isComposite[i]) {
            int p = 2 * i + 1;
            for (ll j = (ll)p * p; j < N; j += 2 * p)
                isComposite[(j - 1) / 2] = true;
        }
    }
}
bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    return !isComposite[(x - 1) / 2];
}
void collectPrimes() {
    primes.push_back(2);
    for (int x = 3; x < N; x += 2) {
        if (isPrime(x)) primes.push_back(x);
    }
}

void solve(){
    sieve();
    int n;cin>>n;
    isPrime(n)?cy:cn;
    
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}