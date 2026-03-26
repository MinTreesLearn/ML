#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000000;

long long aa[N + 1], qu[N + 1];

long long cross(int x0, long long y0, int x1, long long y1) {
	return x0 * y1 - x1 * y0;
}

long long cross(int xi, int xj, int xk) {
	long long yi = aa[xi], yj = aa[xj], yk = aa[xk];
	return cross(xj - xi, yj - yi, xk - xi, yk - yi);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> aa[i];
	for (int i = 1; i <= n; i++)
		aa[i] += aa[i - 1];
	n++;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		while (cnt >= 2 && cross(qu[cnt - 2], qu[cnt - 1], i) <= 0)
			cnt--;
		qu[cnt++] = i;
	}
	for (int h = 0; h + 1 < cnt; h++) {
		int i = qu[h], j = qu[h + 1];
		double a = (double) (aa[j] - aa[i]) / (j - i);
		while (i++ < j)
			printf("%.14f\n", a);
	}
	return 0;
}
