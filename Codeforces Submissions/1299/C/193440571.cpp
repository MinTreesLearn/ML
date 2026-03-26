#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mod 1000000007
#define ll long long int
#define endl '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define EPS 1e-12
#define double long double
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//cout << "0th element: " << *A.find_by_order(0) << endl;
//cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl;
//priority_queue <int, vector<int>, greater<int>>
ll pow1(ll a,ll b){ll ans=1; while(b>0){if(b%2==0){b=b/2;a=(a*a)%mod;}else{b--;ans=(ans*a)%mod;}}return ans;}
ll mod1=1e9+9;
ll pow2(ll a,ll b){ll ans=1; while(b>0){if(b%2==0){b=b/2;a=(a*a)%mod1;}else{b--;ans=(ans*a)%mod1;}}return ans;}
ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
const int N=1e7+2;
void solve()
{
    ll i,a,b,j,n;
    cin>>n;
    vector<pair<ll,ll> >v;
    ll ar[n+2];
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    for(i=1;i<=n;i++)
    {
        v.push_back({ar[i],1});
        int sz=v.size();
        while(sz>1&&v[sz-1].first*v[sz-2].second<v[sz-1].second*v[sz-2].first)
        {
            pair<ll,ll>p={v[sz-1].first+v[sz-2].first,v[sz-1].second+v[sz-2].second};
            v.pop_back();
            v.pop_back();
            v.push_back(p);
            sz--;
        }
    }
    cout<<setprecision(9)<<fixed;
    for(i=0;i<v.size();i++)
    {
        double val1=v[i].first;
        double val2=v[i].second;
        for(j=0;j<v[i].second;j++)
        {
            cout<<val1/val2<<endl;
        }
    }
} 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    t=1;
    int cs=1;
    //cin>>t;
    while (t--)
    {
        //cout<<"Case "<<cs<<": ";
        solve();
        cs++;
    }
}