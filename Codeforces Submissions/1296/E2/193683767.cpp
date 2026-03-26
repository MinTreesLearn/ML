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
const int N=3e5+2;
void solve()
{
    ll n,i,j,a;
    cin>>n;
    string s;
    cin>>s;
    ll ar[n+2],dp[n+2];
    ll mx[27];
    mem(mx,0);
    for(i=0;i<n;i++)
    {
        ar[i]=(int)s[i]-97;
        dp[i]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=25;j>ar[i];j--)
        {
            dp[i]=max(dp[i],mx[j]+1);
        }
        mx[ar[i]]=max(mx[ar[i]],dp[i]);
    }
    ll ans=0;
    for(i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    for(i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
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