/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define sz(s) (int)s.size()
#define maxn 2005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, vis[maxn], f[12][maxn], id[maxn], ans[maxn];
vector<int> S[12][maxn];
//int a[maxn];
inline int query(set<int> v) {
	printf("? %d ", v.size());
	for (auto x: v) printf("%d ", x); printf("\n"); fflush(stdout);
//	int sum = 0; for (auto x: v) sum += a[x];
//	assert(sum % (v.size() / 2) == 0);
//	printf("ans: %d\n", sum % v.size() == 0);
//	return sum % v.size() == 0;
	return read();
}
inline void work(int x, int v) {
//	printf("!!!!!!!!!!!! find that p_%d=%d\n", id[x], v);
	ans[id[x]] = v, vis[x] = 1;
	ru(i, 0, m - 1) f[i][x & ((1 << i) - 1)] = ((x ^ v) >> i) & 1;
}
inline int chk(int x, int y) {
	ru(i, 0, m - 1) {
		int tt = f[i][x & ((1 << i) - 1)];
		if(tt == -1) continue;
//		if(id[x] + y == n + 1 && tt != (((x ^ y) >> i) & 1)) {
//			printf("JILEJILE %d %d %d\n", id[x], y, i);
//		}
		if(tt != (((x ^ y) >> i) & 1)) return 0;
	}
	return 1;
}
mt19937 Rand(time(NULL));
int main() {
	n = read(); //ru(i, 1, n) a[i] = i; shuffle(a + 1, a + n + 1, Rand);
//	a[1] = 2, a[2] = 4, a[3] = 1, a[4] = 6, a[5] = 3, a[6] = 5;
//	ru(i, 1, n) printf("%d ", n - a[i]); printf("\n");
	ru(i, 1, n) S[0][0].push_back(i);
	ru(i, 0, 9) {
		if((1 << (i + 1)) >= n) {
			m = i + 1;
			ru(j, 0, (1 << i) - 1) {
//				printf("!!! %d %d  ", m, j);
//				for (auto x: S[i][j]) printf("%d ", x); printf("\n");
				f[i][j] = -1;
				id[j] = S[i][j][0];
				if(S[i][j].size() > 1) id[j + (1 << i)] = S[i][j][1];
				else vis[j + (1 << i)] = 1;
			}
			break;
		}
		set<int> tmp;
//		ru(j, 0, (1 << i) - 1) {
//			printf("%d %d   ", i, j);
//			for (auto x: S[i][j]) printf("%d ", x);
//			printf("\n");
//		}
//		ru(j, 0, (1 << i) - 1) {
//			for (auto x: S[i][j]) assert(a[x] % (1 << i) == a[S[i][j][0]] % (1 << i));
//		}
		ru(j, 0, (1 << i) - 1) f[i][j] = -1, tmp.insert(S[i][j].back()), tmp.insert(S[i][j][S[i][j].size() - 2]);
//		printf("it's supposed to be %d\n", (1 << (i + 1)));
		int bef = query(tmp);
		ru(j, 0, (1 << i) - 1) {
			int v = S[i][j].back(); S[i][j].pop_back(); tmp.erase(v);
			S[i + 1][j] = {v};
			if(S[i][j].size() == 1) {
				S[i + 1][j + (1 << i)] = {S[i][j][0]};
				tmp.insert(v);
				continue;
			}
			int haha = -1;
			for (auto x: S[i][j]) if(x != S[i][j].back()) {
				tmp.insert(x);
//				printf("bushishenmewanyi\n"); fflush(stdout);
				int aft = query(tmp);
				if(haha == -1) haha = aft;
				S[i + 1][j + ((aft ^ bef) << i)].push_back(x); 
				tmp.erase(x);
			}
//			printf("woc:\n");
			tmp.insert(v);
			tmp.insert(S[i][j][0]);
			tmp.erase(S[i][j].back());
			int aft = query(tmp);
			S[i + 1][j + ((haha ^ aft) << i)].push_back(S[i][j].back());
			tmp.erase(S[i][j][0]);
			tmp.insert(S[i][j].back());
		}
	}
//	printf("m: %d\n", m); ru(j, 0, (1 << m) - 1) printf("%d ", id[j]); printf("\n");
	f[0][0] = 0;
	n--;
	ru(i, 0, n / 2) {
		set<int> t;
		ru(j, 0, (1 << m) - 1) if(!vis[j]) t.insert(id[j]);
		ru(j, 0, (1 << m) - 1) if(!vis[j] && chk(j, i)) {
//			printf("check if p_%d=%d\n", id[j], i);
			t.erase(id[j]);
			if(query(t)) {work(j, i); t.insert(id[j]); break;}
			t.insert(id[j]);
		}
		ru(j, 0, (1 << m) - 1) if(!vis[j] && chk(j, n - i)) {
//			printf("check if p_%d=%d\n", id[j], n - i);
			t.erase(id[j]);
			if(query(t)) {work(j, n - i); break;}
			t.insert(id[j]);
		}
	}
	n++;
//	printf("! "); ru(i, 1, n) printf("%d ", ans[i]);
	ru(i, 1, n) ans[i] = n - ans[i];
	if(ans[1] * 2 > n) {
		ru(i, 1, n) ans[i] = n - ans[i] + 1;
	}
//	ru(i, 1, n) printf("%d ", a[i]); printf("\n");
	printf("! "); ru(i, 1, n) printf("%d ", ans[i]);
	return 0;
}
