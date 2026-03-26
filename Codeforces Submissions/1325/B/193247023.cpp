//ABANOUB FAWAZ
#include <iostream>
#include <iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}


bool com(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return b.second < b.first;
}
ll bs(ll arr[], ll l, ll r, ll key) {
	while (l <= r) {

		ll m = (l + r) / 2;
		if (arr[m] == key)return m;
		if (arr[m] > key)r = m - 1;
		else l = m + 1;
	}
	return -1;
}
bool prime(ll n) {
	if (n <= 1)return 0;
	for (ll i = 2; i * i <= (n); i++) {
		if (n % i == 0)return 0;
	}
	return 1;
}
int primes[1005];
void seive() {
	primes[0] = primes[1] = 0;
	for (int i = 2; i <= sqrt(1000); i++) {
		if (primes[i]) {
			for (int j = 2; j * i <= 1000; j++) {
				primes[j * i] = 0;
			}
		}
	}
}
ll fib(ll n) {
	if (n == 1)return 1;
	if (n == 2)return 2;
	else return fib(n - 1) + fib(n - 2);
}
ll GCD(ll a, ll b) {
	return a == 0 ? b : GCD(b % a, a);
}
ll LCM(ll x, ll y) {
	return x * y / GCD(x, y);
}

bool make_palindrome(string s) {
	map<char, ll>mp;
	ll c = 0;
	for (int i = 0; i < s.size(); i++)mp[s[i]]++;
	for (auto it : mp) {
		if (it.second & 1)c++;
	}
	if (c > 1)return 0;
	return 1;
}
void binary(ll n)
{
	if (n == 0)return;
	binary(n / 2);
	cout << n % 2;
}
int main()
{
	fast();
	const double PI = 3.14159265359;
	ll t; cin >> t; while (t--) {
		ll n; cin >> n; vector<ll>x(n); set<ll>st;
		for (int i = 0; i < n; i++) { cin >> x[i]; st.insert(x[i]); }
		cout << st.size() << "\n";
	}
	return 0;
}