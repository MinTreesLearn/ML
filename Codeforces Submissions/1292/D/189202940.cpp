// BEGIN BOILERPLATE CODE

#include <bits/stdc++.h>
using namespace std;

#ifdef KAMIRULEZ
	const bool kami_loc = true;
	const long long kami_seed = 69420;
#else
	const bool kami_loc = false;
	const long long kami_seed = chrono::steady_clock::now().time_since_epoch().count();
#endif

const string kami_fi = "kamirulez.inp";
const string kami_fo = "kamirulez.out";
mt19937_64 kami_gen(kami_seed);

long long rand_range(long long rmin, long long rmax) {
	uniform_int_distribution<long long> rdist(rmin, rmax);
	return rdist(kami_gen);
}

long double rand_real(long double rmin, long double rmax) {
	uniform_real_distribution<long double> rdist(rmin, rmax);
	return rdist(kami_gen);
}

void file_io(string fi, string fo) {
	if (fi != "" && (!kami_loc || fi == kami_fi)) {
		freopen(fi.c_str(), "r", stdin);
	}
	if (fo != "" && (!kami_loc || fo == kami_fo)) {
		freopen(fo.c_str(), "w", stdout);
	}
}

void set_up() {
	if (kami_loc) {
		file_io(kami_fi, kami_fo);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void just_do_it();

void just_exec_it() {
	if (kami_loc) {
		auto pstart = chrono::steady_clock::now();
		just_do_it();
		auto pend = chrono::steady_clock::now();
		long long ptime = chrono::duration_cast<chrono::milliseconds>(pend - pstart).count();
		string bar(50, '=');
		cout << '\n' << bar << '\n';
		cout << "Time: " << ptime << " ms" << '\n';
	}
	else {
		just_do_it();
	}
}

int main() {
	set_up();
	just_exec_it();
	return 0;
}

// END BOILERPLATE CODE

// BEGIN MAIN CODE

const int ms = 5e3 + 20;
const long long inf = 1e18L + 20;
vector<array<short, ms>> tr;
map<array<short, ms>, int> f;
vector<pair<int, int>> ch[ms * 2];
int cnt[ms * 2];
long long dp[ms * 2];
int sum[ms * 2];
int cc = ms;
long long res = inf;

bool cmp(array<short, ms> &x, array<short, ms> &y) {
	for (int i = ms - 1; i >= 0; i--) {
		if (x[i] != y[i]) {
			return x[i] < y[i];
		}
	}
	return false;
}

array<short, ms> lca(array<short, ms> &x, array<short, ms> &y) {
	array<short, ms> res = {};
	for (int i = ms - 1; i >= 0; i--) {
		if (x[i] == y[i]) {
			res[i] = x[i];
		}
		else {
			res[i] = min(x[i], y[i]);
			break;
		}
	}
	return res;
}

bool anc(array<short, ms> &x, array<short, ms> &y) {
	for (int i = ms - 1; i >= 0; i--) {
		if (x[i] != y[i]) {
			if (x[i] > y[i]) {
				return false;
			}
			for (int j = i - 1; j >= 0; j--) {
				if (x[j] != 0) {
					return false;
				}
			}
			return true;
		}
	}
	return true;
}

int dist(array<short, ms> &x, array<short, ms> &y) {
	int res = 0;
	for (int i = ms - 1; i >= 0; i--) {
		res += y[i] - x[i];
	}
	return res;
}

int get(array<short, ms> &x) {
	auto it = f.find(x);
	if (it == f.end()) {
		return (f[x] = cc++);
	}
	else {
		return it->second;
	}
}

void dfs1(int u) {
	sum[u] = cnt[u];
	for (auto x: ch[u]) {
		int v = x.first;
		int w = x.second;
		dfs1(v);
		sum[u] += sum[v];
		dp[u] += dp[v];
		dp[u] += 1LL * sum[v] * w;
	}
}

void dfs2(int u) {
	res = min(res, dp[u]);
	for (auto x: ch[u]) {
		int v = x.first;
		int w = x.second;
		sum[u] -= sum[v];
		dp[u] -= dp[v];
		dp[u] -= 1LL * sum[v] * w;

		sum[v] += sum[u];
		dp[v] += dp[u];
		dp[v] += 1LL * sum[u] * w;

		dfs2(v);

		dp[v] -= 1LL * sum[u] * w;
		dp[v] -= dp[u];
		sum[v] -= sum[u];

		dp[u] += 1LL * sum[v] * w;
		dp[u] += dp[v];
		sum[u] += sum[v];
	}
}

void just_do_it() {
	tr.emplace_back();
	for (int i = 2; i < ms; i++) {
		tr.push_back(tr.back());
		int x = i;
		for (int j = 2; j < ms; j++) {
			while (x % j == 0) {
				tr[i - 1][j]++;
				x /= j;
			}
		}
	}
	int sz = tr.size();
	for (int i = 0; i < sz; i++) {
		f[tr[i]] = i + 1;
	}
	sort(tr.begin(), tr.end(), cmp);
	for (int i = 0; i < sz - 1; i++) {
		tr.push_back(lca(tr[i], tr[i + 1]));
	}
	sort(tr.begin(), tr.end(), cmp);
	tr.erase(unique(tr.begin(), tr.end()), tr.end());
	sz = tr.size();
	vector<array<short, ms>> p = {tr[0]};
	for (int i = 1; i < sz; i++) {
		int v = get(tr[i]);
		while (!anc(p.back(), tr[i])) {
			p.pop_back();
		}
		int u = get(p.back());
		int w = dist(p.back(), tr[i]);
		ch[u].push_back({v, w});
		p.push_back(tr[i]);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			x = 1;
		}
		cnt[x]++;
	}
	dfs1(1);
	dfs2(1);
	cout << res;
}

// END MAIN CODE