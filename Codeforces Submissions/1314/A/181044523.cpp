#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 2e5 + 10;
int n; pii a[N];

int main() {
	n = read();
	rep(i, 1, n) a[i].fi = read();
	rep(i, 1, n) a[i].se = read();
	
	sort(a + 1, a + n + 1);
	priority_queue<int> q; ll sum = 0, ans = 0;

	int t = 1, p = 1;
	while(p <= n || ! q.empty()) {
		while(p <= n && a[p].fi == t) sum += a[p].se, q.push(a[p ++].se);
		if(q.empty()) {t = a[p].fi; continue;}
		sum -= q.top(); q.pop();
		ans += sum, t ++;
	}
	
	printf("%lld\n", ans);
	return 0;
}
