#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define mod 998244353
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


vi fact(N+3, 1);
vi inv(N+3, 1);

int C(int n, int k) {
    if (k > n) return 0;
    int multiply = (1LL * fact[n] * inv[k]) % mod;
    multiply = (1LL * multiply * inv[n - k]) % mod;
    return multiply;
}


int32_t main(){
	
	fforr(i, N){
		fact[i] = (fact[i-1]*i)%mod;
		inv[i] = power(fact[i], mod-2, mod);
	}
	
	int n, m; cin >> n >> m;
	int ans = 0;
	if(n > 2){
		ans = C(m, n-1)%mod*(n-2)%mod*power(2, n-3, mod)%mod;
	}
	cout << ans << endl;
}