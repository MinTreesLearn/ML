#include<iostream>
#include<vector>
using namespace std;
int n; vector<int>a;
int solve(vector<int>p, int k) {
	if (p.size() == 0 || k < 0)return 0;
	vector<int>p1, p0;
	for (int i : p) {
		if (i & (1 << k))p1.push_back(i);
		else p0.push_back(i);
	}
	if (p1.size() == 0)return solve(p0, k - 1);
	if (p0.size() == 0)return solve(p1, k - 1);
	return (1 << k) + min(solve(p1, k - 1), solve(p0, k - 1));
}
int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <=n; i++)scanf("%d", &x), a.push_back(x);
	printf("%d", solve(a, 30));
}