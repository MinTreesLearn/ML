#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------\n";
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 17 , md = 1e9 + 7 , inf = 2e16;

char c;
bool a[maxn];
vector<ll> v[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k;
	cin>>n>>k;
	if(k > 1) k >>= 1;
	ll m = n / k , x = 0;
	for(ll i = 1 ; i <= n ; i++){
		v[x].push_back(i);
		x += (i % k == 0);
	}
	for(ll t = 1 ; t < m ; t++){
		for(ll s = 0 ; s < t ; s++){
			if(s + t >= m) break;
			for(ll i = s ; i < m ; i += t){
				for(auto j : v[i]){
					cout<<"? "<<j<<endl;
					cin>>c;
					a[j] |= (c == 'Y');
				}
			}
			cout<<"R"<<endl;
		}
	}
	ll cnt = 0;
	for(ll i = 1 ; i <= n ; i++) cnt += !a[i];
	cout<<"! "<<cnt<<endl;
	return 0;
}