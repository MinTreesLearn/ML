//Author : MD GHOUSE MOHIUDDIN
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;

#define ll long long
#define inf INT_MAX
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)  
#define reverse(v) reverse(v.begin(), v.end())    // Reverse a container
#define sort(v) sort(v.begin(), v.end())          // Sort a container
#define reverse_sort(v) sort(v.begin(), v.end(), greater<int>())
#define pi 3.141592653589793238462  
#define vec vector<long long int>
#define input(v) for(auto &x : v){cin>>x;}     
#define display(v)  for(auto x:v){cout<<x<<" ";} cout<<endl;
const long long MOD = 1e9 + 7;
long long string_to_int(string bin);
void sieve_of_eratosthenes(int n,vector<bool> &arr);
long long gcd(long long a, long long b);
bool isPrime(long long n);
void yes() { cout << "YES" << "\n"; }
void no() { cout << "NO" << "\n"; }

ll fun(ll h,ll l,ll r,ll ind,vector<ll>& v,ll currtime,ll n,vector<vector<ll>> &dp)
{
    if(ind == n)
    {
        return 0;
    }
    ll a = 0;
    ll b = 0;
    if(dp[ind][currtime] != -1)
    {
        return dp[ind][currtime];
    }
    ll time = (v[ind] + currtime + h) % h;
    if(time >= l && time <= r)
    {
        a = 1;
    }
    a += fun(h,l,r,ind + 1,v,time,n,dp);
    time = (v[ind] + currtime - 1 + h) % h;
    if(time >= l && time <= r)
    {
        b = 1;
    }
    b += fun(h,l,r,ind + 1,v,time,n,dp);
    return dp[ind][currtime] = max(a,b);
}

void solve()
{
    ll n,h,l,r;
    cin >> n >> h >> l >> r;
    vec v(n);
    input(v);
    vector<vector<ll>> dp(n + 1,vector<ll>(h + 1,-1));
    cout << fun(h,l,r,0,v,0,n,dp) << endl;
}

int main() {
    ios;
    #ifndef ONLINE_JUDGE
        freopen("errorf.in","w",stderr);
    #endif 
    ll t;
    t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
}

long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void sieve_of_eratosthenes(int n,vector<bool> &arr)
{
    arr[0] = false;
    arr[1] = false;
    for(int p = 2;p * p <= n;++p)
    {
        if(arr[p] == true)
        {
            for(int i = p * p;i <= n;i += p)
            {
                arr[i] = false; 
            }
        }
    }
}

ll string_to_int(string bin)
{
    int val = 0;
    ll ans = 0;
    for(int i = bin.size() - 1;i >= 0;--i)
    {
        ans = ans + (bin[i] - '0') * pow(2,val);
        val += 1;
    }
    return ans;
}

bool isPrime(long long n){
    if(n<2)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    for(long long i=3;i*i<=n;i+=2){
        if(n%i==0)return false;
    }
    return true;
}