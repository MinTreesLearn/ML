#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct cust{
    ll t,l,h;
};

void solve(){
    ll n,m,lo,hi;
    cin>>n>>m;
    lo=hi=m;
    vector<cust> a(n);
    for(auto &x:a)cin>>x.t>>x.l>>x.h;
    for(int i=n-1;i>0;i--)a[i].t-=a[i-1].t;
    for(int i=0;i<n;i++){
        if(a[i].h<lo-a[i].t || a[i].l>hi+a[i].t){
            cout<<"NO\n";
            return;
        }
        lo=max(lo-a[i].t,a[i].l);
        hi=min(hi+a[i].t,a[i].h);
    }
    cout<<"YES\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}