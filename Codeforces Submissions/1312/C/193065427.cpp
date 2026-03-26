#include <iostream>
#include <algorithm>
#include<vector>
#include<map>
#include<set>
#include <cmath>
typedef long long ll;
#define pb push_back
#define R return
#define B break
#define C continue
#define lop(i, n) for (int i = 0; i < n; i++)
#define lopp(r, n) for (int r = 1; r < n; r++)
using namespace std;
const int N=2e5+7;
const ll M=1e9+7;
ll a[N];
int fact(int n)
{
	if ((n == 0) || (n == 1))
		return 1;
	else
		return n * fact(n - 1);
}
bool isPrime(int num)
{
	bool flag = true;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}
vector<ll>v;
map<ll,ll>mp;
set<ll>st;
void _clear()
{
	st.clear();mp.clear();v.clear();
}
void solve()
{
	_clear();
	bool f=1;
	ll n,k;
	cin>>n>>k;
	lop(i,n)
	{ll x,p=0;cin>>x;
	while(x>0)
	{
	mp[p++]+=x%k;
	x/=k;
	if(mp[p-1]>=2)f=0;
	}
	}
	if(f)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;   
}
int main()
{
	ll t=1;
	cin>>t;
	while(t--)
solve();
	R 0;
}