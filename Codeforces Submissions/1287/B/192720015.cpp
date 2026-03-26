#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define vi vector <int> 
#define vpi vector <pair<int,int>>
#define vvi vector<vector<int>>
#define mii map <int,int> 
#define mem(a,x) memset(a,x,sizeof(a))
#define endl '\n' 
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define setbits(x) __builtin_popcountll(x)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repb(i,a,b) for(int i=a-1;i>=b;--i)
#define repn(i,a,b,n) for(int i=a;i<b;i+=n)
#define take(a,n) for(int i=0;i<n;++i) cin>>a[i];
#define printv(v) for(auto x:v) cout<<x<<" ";
#define printa(a,n) for(int i=0;i<n;++i) cout<<a[i]<<" ";
#define w(t) int t; cin>>t; while(t--)
#define fastio                        \
ios_base::sync_with_stdio(false);     \
cin.tie(NULL);                        \
cout.tie(NULL);
// const int Mod=998244353; 
const int Mod=1e9+7;

int binaryexp(int a,int b){
	int ans=0;
	if(b<0)return 0;
	if(b==0)return 1;
	else if(b==1)return a;
	else if(b%2){
		ans=(a*(binaryexp((a*a)%Mod,b/2)%Mod))%Mod;
	}
	else ans=binaryexp((a*a)%Mod,b/2)%Mod;
	return ans%Mod;
}

int gcd(int a, int b)
{
return b == 0 ? a : gcd(b, a % b);
}

int32_t main()
{ fastio; 
	int n,k;
	cin>>n>>k;
	vector<string> s(n);
	take(s,n);
	int ans=0;
	rep(i,0,n)
	{   
		set<string> check;
		rep(j,i+1,n)
		{
			string temp;
			rep(l,0,k)
			{
				if(s[j][l]==s[i][l]) temp.pb(s[i][l]);
				else 
				{
					if(s[i][l]=='S' && s[j][l]=='E') temp.pb('T');
					else if(s[i][l]=='S' && s[j][l]=='T') temp.pb('E');
					else if(s[i][l]=='E' && s[j][l]=='S') temp.pb('T');
					else if(s[i][l]=='E' && s[j][l]=='T') temp.pb('S');
					else if(s[i][l]=='T' && s[j][l]=='S') temp.pb('E');
					else if(s[i][l]=='T' && s[j][l]=='E') temp.pb('S');
				}
			}
			if(check.find(temp)!=check.end()) ans++;
			else check.insert(s[j]);
			temp.clear();
		}
		check.clear();
	}
	cout<<ans;
	return 0;
}