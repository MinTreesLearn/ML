#include <bits/stdc++.h>
#define ll long long int
#define take(n) ll n; cin>>n;
#define fo(i,n) for(ll i = 0; i<(ll)n; ++i)
#define rep(i,a,b,d) for(ll i=a; (d<0)?(i>b):(d>0)?i<b:0; i += d)
#define takevect(a,n) vector<ll> a(n); fo(q,n) cin>>a[q];
#define el "\n"
#define pii pair<ll,ll>
#define F first
#define S second
#define elif else if
#define PI atan(1)*4.0
#define dtb(nino,xixo) bitset<nino>(xixo).to_string()
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define maxval INT64_MAX
#define printvect(a) for(auto gar: a) cout<<gar<<' '; cout<<el;
#define print(x) cout<<x<<el;
#define all(bbb) bbb.begin(), bbb.end()
#define mod 1000000007
#define remove(x) erase(x)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define tree_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
bool is_prime(ll n);
vector<ll> sieve(ll n);
vector<ll> Sieve(ll n);
bool is_palindrome(string s);
vector<ll> P;
vector<ll> spf;

void solve(ll tt)
{
	take(n)
	string s; cin >> s;
	map<pii, ll> m;
	ll x = 0, y = 0;
	ll M = 1e9;
	ll X = -1, Y = -1;
	m[{0,0}] = 0;
	for(ll i = 1; i<=n; i++)
	{
		if(s[i-1]=='U') y++;
		if(s[i-1]=='D') y--;
		if(s[i-1]=='L') x--;
		if(s[i-1]=='R') x++;
		if(m.find({x,y})!=m.end())
		{
			ll d = i - m[{x,y}];
			if(M > d)
			{
				M = d;
				X = m[{x,y}]+1;
				Y = i;
			}
		}
		m[{x,y}] = i;
	}
	if(M < 1e9) cout << X <<" " << Y << el;
	else cout << -1 << el;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t{1}; 
	cin>>t;
 	fo(tt,t)
	{
		solve(tt);
	}
	return 0;
}

bool is_prime(ll n)
{
	if(n<=3) return true;
	if(n%2==0 || n%3==0) return false;
	ll i{5};
	while(i*i <= n)
	{
		if(n%i==0 || n%(i+2)==0) return false;
		i += 6;
	}
	return true;
}

vector<ll> sieve(ll n)
{
   	vector<ll> prime(n+1,-1);
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == -1) 
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = p;
        }
    }
    for(ll i = 2; i<=n; i++)
    {
    	if(prime[i]==-1) prime[i] = i;
    }
    return prime;
}

vector<ll> Sieve(ll n)
{
	vector<bool> prime(n+1, true);
	for(ll p = 2; p*p<=n; p++)
	{
		if(prime[p])
		{
			for(ll i = p*p; i <= n; i += p)
				prime[i] = false;
		}
	}

	vector<ll> z;
	for(ll i = 2; i<=n; i++)
		if(prime[i]) z.pb(i);
	return z;
}

bool is_palindrome(string s)
{
	int l = s.length();
	for(int i=0;i<=l/2;i++)
	{
		if(s[i]!=s[l-i-1]) return false;
	}
	return true;
}