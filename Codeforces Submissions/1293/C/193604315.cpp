#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define sqr(x) (x)*(x)
#define inn(n) for (int i = 0;i < (n);i++)
#define vi vector<int>
#define str string
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); cout.setf(ios::fixed);cout.precision(0);
using namespace std;
 
const ll mx = 1e9 + 7,mn = -1000000000 - 7;
const ld pi = 3.1415926535897932384626433832795;
string pr = " ";
ll binpow (ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}
int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}
int sum_of_digits (int a) {
	int ans = 0;
	while (a > 0) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}
int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}
ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}
const int N = 1e5;
int block[3][N+2];
void solve(){
	int n, q; cin >> n >> q;
	int r, c;
	set <pair <int, int> > blocks;
	
	while (q--) {
		cin >> r >> c;
		if (block[r][c]) {
			block[r][c] = 0;
			if (r == 1) {
				if (block[2][c - 1]) {
					blocks.erase(blocks.find({c, c - 1}));
				}if (block[2][c]) {
					blocks.erase(blocks.find({c, c}));
				}
				if (block[2][c + 1]) {
					blocks.erase(blocks.find({c, c + 1}));
				}
			}
			else {
				if (block[1][c - 1]) {
					blocks.erase(blocks.find({c - 1, c}));
				}if (block[1][c]) {
					blocks.erase(blocks.find({c, c}));
				}
				if (block[1][c + 1]) {
					blocks.erase(blocks.find({c + 1, c}));
				}
			}
		}
		else {
			block[r][c] = 1;
			if (r == 1) {
				if (block[2][c - 1]) {
					blocks.insert({c, c - 1});
				}if (block[2][c]) {
					blocks.insert({c, c});
				}
				if (block[2][c + 1]) {
					blocks.insert({c, c + 1});
				}
			}
			else {
				if (block[1][c - 1]) {
					blocks.insert({c - 1, c});
				}if (block[1][c]) {
					blocks.insert({c, c});
				}
				if (block[1][c + 1]) {
					blocks.insert({c + 1, c});
				}
			}
		}
		if (blocks.size() == 0) cout << "Yes";
		else cout << "No";
		cout << '\n';
	}
	return;
}

int main(){
    ios
    int test = 1; //cin >> test;
    while (test--) {
		solve();
		cout << '\n';
	}
	return 0;
}
