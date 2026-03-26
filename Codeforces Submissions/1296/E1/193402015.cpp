#include <bits/stdc++.h>	
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) x.begin(), x.end()
#define pb push_back
#define int long long
#define pop pop_back
#define v_i vector <int>
#define f1 first
#define s2 second
#define vp vector<pair <int, int>>
using namespace std;
using namespace __gnu_pbds;

typedef long long lli;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
long long binpow(long long a, long long b)
{
    if(b==0) return 1;
    long long res = binpow(a, b/2);
    if(b%2==0) return res*res;
    else return res*res*a;
}
void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    vector <int> v;
    for(int i=0;i<n;i++) v.pb(0);
    for(int i=1;i<n;i++){
        set <int> se;
        for(int j=i-1;j>=0;j--){
            if(s[i]<s[j]){
                se.insert(v[j]);
            }
        }
        if(se.size()==1) {v[i]=!(*se.begin());}
        if(se.size()==2) {cout<<"NO"<<endl; return;}
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++) cout<<v[i];
    cout<<endl;
}
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {
        solve();
    }
}