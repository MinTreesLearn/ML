#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }

#ifdef LOCAL
#define debug(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define debug(...) "zzz"
#endif

using LL = long long;
using LD = long double;
using pii = pair<LL,LL>;

#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),decltype(end(declval<T>()))>> : true_type {};
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v) {
	cout << "["; 
	for (auto it = v.begin(); it != v.end();) {
		cout << *it;
		if (++it != v.end()) cout << ", ";
	}
	return cout << "]";
}

//var 
LL T;

vector<int> graham_scan(vector<pii>& points) {
	int N = points.size();
	vector<int> process(N);
	iota(all(process), 0);

	sort(all(process), [&points](int a, int b) {
		return points[a] < points[b];
	});

	//debug(points);

	vector<int> hull(N + 1);
	int idx = 0;
	auto cross = [&](int a, int b, int c) -> LL {
		return 1LL * (points[b].first - points[a].first) * 
					 (points[c].second - points[a].second) -
			   1LL * (points[b].second - points[a].second) *
			   		 (points[c].first - points[a].first);
	};

	for (int i = 0; i < N; i++) {
		while (idx >= 2 && cross(hull[idx - 2], hull[idx - 1], process[i]) >= 0) {
			idx--;
		}
		hull[idx++] = process[i];
	}

	int half = idx;
	for (int i = N - 2; i >= 0; i--) {
		while (idx > half && cross(hull[idx - 2], hull[idx - 1], process[i]) >= 0)
			idx--;
		hull[idx++] = process[i];
	}
	idx--;
	vector<int> ret;
	for (int i = half; i < idx; i++)
		ret.pb(hull[i]);
	ret.pb(hull[0]);
	return ret;
}

void solve() {
	LL n; cin >> n;
	vector<LL> a(n);

	for (auto& u : a)
		cin >> u;

	vector<pii> b(n + 1);
	FOR (i, n) {
		b[i].f = i;
 		b[i].s = a[i - 1];
		b[i].s += b[i - 1].s;
	}

	vector<int> lower = graham_scan(b);
	LL starting_point = 1;
	lower.pop_back();
	reverse(all(lower));

	vector<LD> ans(n);
	for (auto u : lower) {
		LD running = 0;
		LL cnt = 0;
		for (int i = starting_point; i <= u; i++) {
			running += a[i - 1];
			cnt++;
		}

		for (int i = starting_point; i <= u; i++) {
			ans[i - 1] = running / cnt;
		}

		starting_point = u + 1;
	}

	LD running = 0;
	LL cnt = 0;
	for (int i = starting_point; i <= n; i++) {
		running += a[i - 1];
		cnt++;
	}

	for (int i = starting_point; i <= n; i++) {
		ans[i - 1] = running / cnt;
	}

	cout << fixed << setprecision(10);
	for (auto& u : ans)
		cout << u << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	T = 1;
	//cin >> T;
	FOR(t, T)
		solve();

	cout.flush();
	return 0;
}

