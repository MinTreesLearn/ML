/*
....###....########..##....##....###....##....##............##....#######.
...##.##...##.....##..##..##....##.##...###...##..........####...##.....##
..##...##..##.....##...####....##...##..####..##............##...##.....##
.##.....##.########.....##....##.....##.##.##.##............##....########
.#########.##...##......##....#########.##..####............##..........##
.##.....##.##....##.....##....##.....##.##...###............##...##.....##
.##.....##.##.....##....##....##.....##.##....##.#######..######..#######.

*/
#include <bits/stdc++.h>
using namespace std;
 
 
typedef  long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
 
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define vll vector <ll>
#define pb push_back
#define pf push_front
#define mp make_pair
#define f(i,j,k) for(ll i=j;i<k;i++)
#define fr(i,j,k) for(ll i=j;i>=k;i--)
#define MOD 1000000007
#define MOD1 998244353
#define pi 3.141592653589
#define eq enqueue
#define dq dequeue
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d)) 
#define lcm(a,b) (a*(b/gcd(a,b)))
#define INF 2e18
#define ff first
#define ss second
 
 
#ifndef ONLINE_JUDGE
#define debug(val) cerr << (#val) << ": " << val << endl
#else
#define debug(val)
#endif
/////////////////////////////////////////////////////////////////////////////////// 
//power  
long long power(long long x, unsigned long long y)
{
    long long temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
 
// modular exponentiation-iterative approach.
 
long long modpow(long long x, unsigned int y, long long p)
{
    ll res = 1;  
 
    x = x % p; 
    if(y==0)
        return 1;
  
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
 
// modular exponentiation-recursive approach.
 
long long exponentMod(long long A, long long B, long long C)
{
       if (B == 0)
        return 1;
    if (A == 0)
        return 0;
    long long y;
    if (B % 2 == 0) {
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
    }
    else {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }
 
    return (long long)((y + C) % C);
}
// GCD of two numbers (Time Complexity: O(Log min(a, b))  )
long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
   
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
// Function to find modulo inverse of a
void modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        int res = (x % m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
    }
}
 
// sieve of eratosthenes
void SieveOfEratosthenes(int n)
{
    bool sieve[n + 1];ll cnt=0;
    memset(sieve, 0, sizeof(sieve));
 
    for (int p = 2; p * p <= n; p++)
    {
        
        if (!sieve[p])
        {
           
            for (int i = 2 * p; i <= n; i += p)
                sieve[i] = p;
        }
    }
 
    for (int p = 2; p <= n; p++)
       { if (sieve[p])
            cnt++;}
        cout<<cnt;
}
 
//euler's totient-number of coprime numbers to n between 1 and n.(excluding n)
 
int phi(unsigned int n)
{
    float result = n;
    for(int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
                 
            result *= (1.0 - (1.0 / (float)p));
        }
    }
  
    if (n > 1)
        result *= (1.0 - (1.0 / (float)n));
  
    return (int)result;
}
 
 
// //finding square root in O(logN).
// ll floorSqrt(ll x){    
// 	if (x == 0 || x == 1)
// 	return x;
// 	unsigned long long start = 1, end = x, ans;
// 	while (start <= end)
// 	{        
// 		unsigned long long mid = start+(end-start)/2;
 
// 		if (mid*mid == x)
// 			return mid;
 
// 		if (mid*mid < x)
// 		{
// 			start = mid + 1;
// 			ans = mid;
// 		}
// 		else end = mid-1;              
// 	}
// 	return ans;
// }
 
 
 
/******************************************START OF PROGRAM LOGIC***************************************************/
 
int32_t main()
{
   FIO;
   ll t;
   cin>>t;
   while(t--)
   {
     ll n,m,k;
     cin>>n>>m>>k;
     ll a[n+1];
     f(i,0,n)
     {
        cin>>a[i];
     }
    //  vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(m+1, vector<ll>(k+1,-1)));
    //  cout<<solve()
    k=min(m-1,k);
    ll ans=0;
    f(i,0,k+1)
    {
        ll mini=LLONG_MAX;
        f(j,0,(m-k))
        {
            mini=min(mini, max(a[i+j], a[i+j+(n-m)]));
        }
        ans=max(ans,mini);
    }
    cout<<ans<<endl;
 
 
 
 
   }
 
 
 
}