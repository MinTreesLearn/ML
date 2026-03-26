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

const int ms = 2e3 + 20;
const int inf = 1e9 + 20;
const int st = 11;
int a[ms];
int b[ms];
int c[ms * 2];
int dp[ms][1 << st];
int best1[ms];
int best2[ms];

int calc(int x, int y) {
	int res = 0;
	bool ok = false;
	for (int i = 0; i < st; i++) {
		res += c[x + i];
		if (!((y >> i) & 1)) {
			ok = true;
			break;
		}
	}
	assert(ok);
	return res;
}

void just_do_it() {
	fill_n(&dp[0][0], ms * (1 << st), -inf);
	dp[0][0] = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n + m; i++) {
		cin >> c[i];
	}
	for (int i = n; i >= 1; i--) {
		for (int k = a[i]; k >= max(0, a[i] - st); k--) {
			for (int j = (1 << st) - 1; j >= 0; j--) {
				if (dp[k][j] == -inf) {
					continue;
				}
				int nj = j >> (a[i] - k);
				dp[a[i]][nj + 1] = max(dp[a[i]][nj + 1], dp[k][j] + calc(a[i], nj) - b[i]);
			}
		}
		dp[a[i]][1] = max(dp[a[i]][1], best2[max(0, a[i] - st)] + c[a[i]] - b[i]);
		best1[a[i]] = -inf;
		for (int j = 0; j < (1 << st); j++) {
			best1[a[i]] = max(best1[a[i]], dp[a[i]][j]);
		}
		for (int i = 1; i <= m; i++) {
			best2[i] = max(best2[i - 1], best1[i]);
		}
	}
	cout << best2[m];
}

// END MAIN CODE