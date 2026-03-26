#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define foia(a, b) for(ll i = a; i < (b); i++)
#define foib(a, b) for(int i = b-1; i>=a ; i--)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
#define foi(n) for (ll i = 0; i < n; i++)
#define foj(n) for (ll j = 0; j < n; j++)
typedef vector<ll> vll;
typedef map<ll, ll> mll;
typedef vector<pair<ll, ll> > vpll;


bool isPrime(int n){
if(n==1) return false;
if(n==2) return true;
for(int i=2;i*i<=n;i++){
if(n%i==0)return false;
}
return true;
}

ll mod_mul(ll a, ll b){
a = a % mod;
b = b % mod;
return (((a * b) % mod) + mod) % mod;
}


ll mod_add(ll a, ll b){
a = a % mod;
b = b % mod;
return (((a + b) % mod) + mod) % mod;
}


int main(){
fast
int t=1;
cin>>t;
while(t!=0){
	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vll v(m);
	map<ll,ll> p;
	foi(m)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(ll i=0;i<s.length();i++)
	{
		p[s[i]-97]++;
	}
	ll j=0,k=v.size();
	foi(v.size())
	{
		while((v[i])!=j)
		{
			p[s[j]-97]+=(k);
			j++;
		}
		if((i+1)!=v.size() && v[i]==v[i+1])
		{
			while((i+1)!=v.size() && v[i]==v[i+1])
			{
				i++;
				k--;
			}
		}
		k--;
	}
	foi(26)
	{
		if(p.find(i)==p.end())
		{
			cout<<0<<" ";
		}
		else
		{
			cout<<p[i]<<" ";
		}
	}
	cout<<endl;
t--;
}
return 0;
}
