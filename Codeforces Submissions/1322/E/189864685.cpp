// BEGIN BOILERPLATE CODE

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const int ms = 5e5 + 20;
const int inf = 1e9 + 20;
int a[ms];
pair<int, int> p[ms];
int b[ms];
int res[ms];
int pos;

void fix(int &lt, int &rt) {
	if (lt == 0) {
		lt = -inf;
		rt = inf;
	}
	else if (b[lt] == 1 && b[rt] == 1) {
		lt = -inf;
		rt = inf;
	}
	else if (b[lt] == 2 && b[rt] == 1) {
		rt = (lt + rt) / 2;
	}
	else if (b[lt] == 1 && b[rt] == 2) {
		lt = (lt + rt) / 2 + 1;
	}
}

void inter(int &l1, int &r1, int l2, int r2) {
	if (l1 > r1 || l2 == -inf) {
		return;
	}
	if (l1 <= min(r1, l2 - 1)) {
		r1 = min(r1, l2 - 1);
	}
	else if (max(l1, r2 + 1) <= r1) {
		l1 = max(l1, r2 + 1);
	}
	else {
		l1 = inf;
		r1 = -inf;
	}
}

void update(int l1, int r1, int l2, int r2, int l3, int r3, int val) {
	fix(l1, r1);
	if (l1 == -inf) {
		return;
	}
	b[pos] = 1;
	fix(l2, r2);
	fix(l3, r3);
	b[pos] = 2;
	inter(l1, r1, l2, r2);
	inter(l1, r1, l3, r3);
	for (int i = l1; i <= r1; i++) {
		if (res[i] != -1) {
			exit(0);
		}
		res[i] = val;
	}
}

void just_do_it() {
	int n, k;
	cin >> n;
	k = 1;
	//cin >> k;
	set<int> s;
	multiset<int> len;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = {a[i], i};
		b[i] = 1;
		res[i] = -1;
		s.insert(i);
		len.insert(1);
	}
	int mx = 1;
	sort(p + 1, p + n + 1, greater<>());
	for (int i = 1; i <= n; i++) {
		int l1 = -1;
		int r1 = -1;
		int l2 = -1;
		int r2 = -1;
		int l3 = -1;
		int r3 = -1;
		int val = p[i].first;
		pos = p[i].second;
		auto it = prev(s.upper_bound(pos));
		l2 = (*it);
		if (it != s.begin()) {
			it--;
			r1 = l2 - 1;
			l1 = (*it);
			it++;
		}
		it++;
		if (it == s.end()) {
			r2 = n;
		}
		else {
			r2 = (*it) - 1;
			l3 = r2 + 1;
			it++;
			if (it == s.end()) {
				r3 = n;
			}
			else {
				r3 = (*it) - 1;
			}
		}
		b[pos] = 2;
		if (l2 == r2 && l2 > 1 && r2 < n) {
			update(l1, r3, l1, r1, l3, r3, val);
			len.erase(len.find(r1 - l1 + 1));
			s.erase(l2);
			len.erase(len.find(r2 - l2 + 1));
			s.erase(l3);
			len.erase(len.find(r3 - l3 + 1));
			len.insert(r3 - l1 + 1);
		}
		else {
			len.erase(len.find(r2 - l2 + 1));
			if (pos > l2) {
				update(l2, pos - 1, l2, r2, 0, 0, val);
				len.insert(pos - l2);
			}
			else {
				s.erase(l2);
			}
			if (pos < r2) {
				update(pos + 1, r2, l2, r2, 0, 0, val);
				s.insert(pos + 1);
				len.insert(r2 - pos);
			}
			if (pos == l2 && l2 > 1) {
				update(l1, pos, l1, r1, 0, 0, val);
				len.erase(len.find(r1 - l1 + 1));
				len.insert(pos - l1 + 1);
			}
			else if (pos == r2 && r2 < n) {
				update(pos, r3, l3, r3, 0, 0, val);
				s.erase(l3);
				len.erase(len.find(r3 - l3 + 1));
				s.insert(pos);
				len.insert(r3 - pos + 1);
			}
			else {
				update(pos, pos, l2, r2, 0, 0, val);
				s.insert(pos);
				len.insert(1);
			}
		}
		if (val != p[i + 1].first) {
			mx = max(mx, *len.rbegin());
		}
	}
	cout << (mx - 1) / 2 << '\n';
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			cout << res[i] << " ";
		}
	}
}

// END MAIN CODE