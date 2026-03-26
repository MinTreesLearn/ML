#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

const int N = 1050;
int n, k, len, blo; bool ans[N];

void clr() {cout << "R" << endl;}

bool ask(int x) {
	cout << "? " << x << endl;
	char rec; cin >> rec; return (rec == 'Y');
}

void calc(int x) {
	int l = (x - 1) * len + 1;
	int r = x * len;
	rep(i, l, r) if(ans[i] && ask(i)) ans[i] = false; 
}

int main() {
	scanf("%d %d", &n, &k);
	len = k;
	blo = n / k;
	
	rep(i, 1, n) ans[i] = true;
	rep(s, 1, blo) {
		if(s > 1) clr();
		for(int d = 0, i = 1; i <= blo; i ++) {
			int x = s + d;
			while(x <= 0) x += blo;
			while(x > blo) x -= blo;
			calc(x);
			if(d >= 0) d = - d - 1; else d = - d;
		}
	}
	
	int Ans = 0;
	rep(i, 1, n) Ans += ans[i];
	cout << "! " << Ans << endl;
	return 0;
}
