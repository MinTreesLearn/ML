#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int) (a).size())
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int N=2e5;
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
void solve(){
	double n,d;
	cin>>n>>d;
	for (int i=0;i<=sqrt(d);i++){
		ll ans = ceil(d/(i+1))+i;
		if(ans<=n){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	solve();
	}
}
