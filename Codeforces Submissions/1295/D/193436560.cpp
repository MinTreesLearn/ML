// Problem: D. Same GCDs
// Contest: Codeforces - Educational Codeforces Round 81 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1295/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define mod 1000000007
#define N 500005
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define control ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long int
#define ffor(i, n) for(int i=0; i<n; i++)
#define fforr(i, n) for(int i=1; i<=n; i++)
#define rfor(i, n) for(int i=n-1; i>=0; i--)
#define rforr(i, n) for(int i=n; i>0; i--)
#define all(x) x.begin(), x.end()
#define F  first
#define S  second
#define inf 9223372036854775807
using namespace std;
void setIO()
{	
	control;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
void print(bool chk){
	if(chk){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
int min(int a, int b){
	return a>b?b:a;
}
int max(int a, int b){
	return a<b?b:a;
}
int power(int x,int y,int p)
{
    int ans=1;
    x=x%p;
    if(x==0)
    {
    	return 0;
    }
    while(y>0)
    {
        if(y&1)
        {
        	ans=(ans*x)%p;
        }
        y=y>>1;
        x=(x*x)%p;
    }
    return ans;
}

int phi(int m){
	int x=2;
	int ans = m;
	while(x*x <= m){
		int cnt = 0;
		while(m%x == 0){
			m/=x;
			cnt++;
		}
		if(cnt)ans -= ans/x;
		x++;
	}
	if(m>1)ans -= ans/m;
	return ans;
}

int32_t main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		cout << phi(m/__gcd(n, m)) << endl;
	}
}