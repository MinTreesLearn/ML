// #Ashutosh Gautam </> Codes :)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Debugging purpose :))
#ifdef AshutoshGautam
#include "AshutoshDebugger.hpp" 
// #define cerr cout
#else
#define deb(...)
#endif
template <class T> void debug(vector<T>adj[], int n);

typedef long long int ll;
#define int long long int
#define double long double
#define FastandFurious ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define inf (int)1e18+2
#define all(x) (x).begin(),(x).end()
#define gcd __gcd

template<class T> using ordered_set = tree<T, null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
// s.find_by_order(k)  returns iterator to kth element starting from 0;
// s.order_of_key(k) returns count of elements strictly smaller than k;
const int N = 2e5+10;
const int mod = 1e9+7;

// For laziness ;)
vector<int>g[N],level(N),lo_prime(N,0),hi_prime(N,0);
vector<bool> isPrime(N+1, true),vis(N,false);

bool powerof2(int x){return x&& (!(x&(x-1)));}
int totalDigits(int n){if(n == 0) return 1;return floor(log10(n))+1;}
long long power(long long a, long long b);
long long powerM(long long a, long long b);
int inv(int n, int p = mod){return powerM(n, p-2);}
void primeseive();
void PrimeFactors(ll n, vector<pair<ll, ll>> &v);
void dfs(int vertex);
void bfs(int source);

/*-----------------------------#Maincode Starts! FrontEnd :) -----------------------------------*/

/* 
    dp[i][j][k] -> maximum value you can get from (arr[i]....to....arr[j]) 
    if you can manipulate k people

    means if chosen elememts are <= k you can manipulate them
    means you can keep count of people you have chosen so far.

    so your dp state will be reduced to 
    dp[i][j][chosen] 

    but wait if you know total number of chosen people & one pointer let say i 
    then you can calculate j in O(1) because i + (n-1-j) == chosen

    so your dp state will be reduced to dp[i][j] and if chosen <= k you will minimise the 
    current value otherwise you will maximise
*/
vector<vector<int>>dp;
int func(int i, int j, int n, int m, int k, vector<int>&v)
{
    int chosen = i + (n-1-j);
    if(chosen >= m-1) return max(v[i],v[j]);

    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;

    if(chosen < k)
        ans = max(func(i+1,j,n,m,k,v),func(i,j-1,n,m,k,v));
    else 
        ans = min(func(i+1,j,n,m,k,v),func(i,j-1,n,m,k,v));

    return dp[i][j] = ans;
}
void MainCode()
{
    int n, m, k; cin >> n >> m >> k;
    vector<int>v(n); for(int &x : v) cin >> x;

    dp.clear();
    dp.resize(n,vector<int>(n+1,-1));
    cout << func(0,n-1,n,m,k,v) << "\n";
}
/*-----------------------------#Maincode Ends! BackEnd :)) -------------------------------------*/
signed main()
{
    FastandFurious

    int TestCaseS = 1;
    cin >> TestCaseS; 

    // primeseive();
    for(int TestCase = 1; TestCase <= TestCaseS ; TestCase++)
    {
        // cout << "Case #" << TestCase << ": "; // Google!
        MainCode();
    }
    return 0;
}

template <class T> void debug(vector<T>adj[], int n)
{for(int i = 0; i < n; i++){cout<<"adj["<<i<<"]=";show_me(adj[i]);cout << endl;}}
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long powerM(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res%mod * a%mod)%mod;
        a = (a%mod * a%mod)%mod;
        b >>= 1;
    }
    return res;
}
void primeseive()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++) 
    {
        if (isPrime[i]) 
        {
            lo_prime[i] = hi_prime[i] = i; // For prime numbers 
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;

                hi_prime[j] = i; // For calculating Prime factorization in O(LogN)
                if(lo_prime[j] == 0) lo_prime[j] = i;
                // https://github.com/ashuthe1/myTemplates/blob/main/primeInLogN.cpp
            }
        }
    }
}
void PrimeFactors(ll n, vector<pair<ll, ll>> &v)
{
    for (int i = 2; (i * i) <= n; i++)
    {
        if (n % i != 0)
            continue;
        ll cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            ++cnt;
        }
        v.push_back({i, cnt});
    }
    if (n != 1)
        v.push_back({n, 1});
    sort(v.begin(), v.end());
}
void dfs(int vertex)
{
    /* Take action on vertex after
     entering the vertex
    */
    vis[vertex] = true;
    
    for(int child : g[vertex])
    {
        /* Take action on child before
        entering the child node */

        if(vis[child]) continue;

        dfs(child);

        /* Take action on child after
        exiting the child node */   
    }
    /* Take action on vertex
    before exiting the vertex */
}
void bfs(int source)
{
    queue < int > q;
    q.push(source);
    vis[source] = 1;

    while (!q.empty())
    {
        int curr_v = q.front();
        q.pop();

        for(int child : g[curr_v]){

            if(!vis[child]){

                q.push(child);
                vis[child] = 1;
                level[child] = level[curr_v]+1;

            }
        }
    } 
}