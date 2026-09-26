#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define nf cout<<'\n'
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()

const int N=1e6+5;
vector<int> seg(N*4);
vector<int> a(N);

void build(int node,int l,int r){
    if(l==r){
        seg[node]=a[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node]=seg[node*2]+seg[node*2+1];
}
void update(int node,int l,int r,int idx,int val){
    if(idx < l || idx > r) return;
    if(l==r){
        seg[node]=val;
        return;
    }
    int mid=l+(r-l)/2;
    if(idx>=l && idx<=mid)update(node*2,l,mid,idx,val);
    else update(node*2+1,mid+1,r,idx,val);
    seg[node]=seg[node*2]+seg[node*2+1];
}
int query(int node,int l,int r,int ll,int rr){
    if(r<ll || l>rr) return 0LL;
    if(l>=ll && r<=rr)return seg[node];
    int mid=l+(r-l)/2;
    int left=query(node*2,l,mid,ll,rr);
    int right=query(node*2+1,mid+1,r,ll,rr);
    return left+right;
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    cout<<query(1,1,n,1 ,10)<<nl;;
    update(1,1,n,7,5);
    cout<<query(1,1,n,1 ,10)<<nl;;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}