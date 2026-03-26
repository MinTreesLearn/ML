#include <bits/stdc++.h>
#include <regex>
using namespace std;
#pragma region defines
#define pll pair<ll, ll>
#define pss pair<str, str>
#define vll vector<ll>
#define vstr vector<str>
#define vvll vector<vector<ll>>
#define vpll vector<pll>
#define vvpll vector<vector<pll>>
#define spll set<pll>
#define sll set<ll>
#define pld pair<ld, ld>
#define vld vector<ld>
#define vvld vector<vector<ld>>
#define vpld vector<pld>
#define sld set<ld>
#define PI 3.14159265358979323846
#define pout(x) cout << fixed << setprecision(x)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FR freopen("in.txt", "r", stdin);
#define FW freopen("out.txt", "w", stdout);
#define pb push_back
#define ins insert
#define mp make_pair
#define siz(x) (ll)x.size()
#define all(x) x.begin(), x.end()
#define alln(x, n) x.begin(), x.begin() + n
#define summ(a) (accumulate((a).begin(), (a).end(), 0ll))
#define mine(a) (*min_element((a).begin(), (a).end()))
#define maxe(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
template<class T1, class T2> istream& operator>>(istream& in, pair<T1, T2>& a) { in >> a.first >> a.second; return in; }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2>& a) { out << a.first << ' ' << a.second; return out; }
#pragma endregion
#define mod 1999871
#define INF (ll)300000000000000000
const double EPS = 1e-12;
void solve();
ll _ = 1, n, a[300], b[300];
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	ll pmax = 0;
	ll win = 0, lose = 0;
	bool k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0 and b[i] == 1) {
			lose++;
		}
		else if (a[i] == 1 and b[i] == 0) {
			win++;
			k = 1;
		}
		else if (a[i] == 1 and b[i] == 1) {
			pmax = max(pmax, 1ll);
		}
	}
	if (!k) {
		cout << -1 << endl;
		return;
	}
	cout << ((lose + 1) / win) + !!((lose + 1) % win) << endl;
}
int main() {
	srand(time(NULL));
	IOS;
	//FR;
	//FW;
	//cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}