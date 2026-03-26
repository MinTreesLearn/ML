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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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
const int N=5e5+5;
int sp1[N][22],sp2[N][22],val1[N],val2[N],ar[N],br[N],cr[N],dr[N];
void sparse1(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        sp1[i][0]=val1[i+1];
    }
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;i<=n-(1<<j);i++)
        {
            sp1[i][j]=max(sp1[i][j-1],sp1[i+(1<<(j-1))][j-1]);
        }
    }
}
void sparse2(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        sp2[i][0]=val2[i+1];
    }
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;i<=n-(1<<j);i++)
        {
            sp2[i][j]=max(sp2[i][j-1],sp2[i+(1<<(j-1))][j-1]);
        }
    }
}
ll check1(ll a,ll b)
{
    ll c=(b-a)+1;
    c=(int)log2(c);
    return max(sp1[a][c],sp1[b-(1<<c)+1][c]);
}
ll check2(ll a,ll b)
{
    ll c=(b-a)+1;
    c=(int)log2(c);
    return max(sp2[a][c],sp2[b-(1<<c)+1][c]);
}
void solve()
{
    int n,i,a,b,c,d,e,j;
    cin>>n;
    map<int,int>mp;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i]>>br[i]>>cr[i]>>dr[i];
        mp[ar[i]]=1;
        mp[br[i]]=1;
        mp[cr[i]]=1;
        mp[dr[i]]=1;
    }
    a=1;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        (*it).second=a++;
    }
    for(i=1;i<=n;i++)
    {
        ar[i]=mp[ar[i]];
        br[i]=mp[br[i]];
        cr[i]=mp[cr[i]];
        dr[i]=mp[dr[i]];
        val1[ar[i]]=max(val1[ar[i]],cr[i]);
        val1[br[i]]=max(val1[br[i]],cr[i]);
        val2[cr[i]]=max(val2[cr[i]],ar[i]);
        val2[dr[i]]=max(val2[dr[i]],ar[i]);
    }
    sparse1(a);
    sparse2(a);
    for(i=1;i<=n;i++)
    {
        a=ar[i],b=br[i];
        if(check1(a-1,b-1)>dr[i])
        {
            cout<<"NO"<<endl;
            return;
        }
        a=cr[i],b=dr[i];
        if(check2(a-1,b-1)>br[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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