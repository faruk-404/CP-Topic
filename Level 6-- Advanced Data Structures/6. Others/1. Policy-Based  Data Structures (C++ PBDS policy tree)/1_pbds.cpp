#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define nl '\n'
#define nf cout<<'\n'
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()    //pb.order_of_key(x); x>cnt
#define rall(v) v.rbegin(),v.rend()  //pb.find_by_order(idx); valu

template<typename T> using pbds=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//template<typename T> using pbds=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    pbds<int> pb;
    for(auto i:a){
        pb.insert(i);
    }
    int x;cin>>x;
    cout<<pb.order_of_key(x)<<nl;
    int idx;cin>>idx;
    cout<<*pb.find_by_order(idx)<<nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}