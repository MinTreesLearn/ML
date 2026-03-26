#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 5e5 + 5;

set<int> not_in_res, alter_seg;

int n, m, a[N], b[N], res[N];
vector<int> pos[N];

void update(int l, int r, int v) {
	auto it = not_in_res.lower_bound(l);
	while (it != not_in_res.end() && *it <= r) {
		res[*it] = v;
		not_in_res.erase(it);
		it = not_in_res.lower_bound(l);
	}
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	vector<int> vals(a + 1, a + n + 1);
	
	sort(vals.begin(), vals.end());
	vals.resize(m = (unique(vals.begin(), vals.end()) - vals.begin()));

	for (int i = 1; i <= n; i++)
		pos[a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin()].push_back(i);

	int longest_segment_size = 0;


	for (int i = 0; i <= n; i++)
		alter_seg.insert(i);
	for (int i = 1; i <= n; i++)
		not_in_res.insert(i);

	for (int i = 0; i < m; i++) {
		for (int p : pos[i]) { // b[p] : 0 -> 1
			if (p > 1 && !b[p - 1])
				alter_seg.erase(p - 1);
			else
				alter_seg.insert(p - 1);

			if (p < n && !b[p + 1])
				alter_seg.erase(p);
			else
				alter_seg.insert(p);

			b[p] = 1;
		}
		for (int p : pos[i]) {
			for (int x : {p - 1, p, p + 1}) if (x >= 1 && x <= n) {
				auto it = alter_seg.lower_bound(x);
				int r = *it, l = *(-- it) + 1, m = (l + r) / 2;
				if (b[l]) update(l, m + 0, vals[i]);
				if (b[r]) update(m + 1, r, vals[i]);
				longest_segment_size = max(longest_segment_size, r - l);
			}
		}
	}

	cout << longest_segment_size / 2 << '\n';
	for (int i = 1; i <= n; i++)
		cout << res[i] << " \n"[i == n];
}