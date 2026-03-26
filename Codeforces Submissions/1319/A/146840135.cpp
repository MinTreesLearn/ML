#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
typedef  long long int ll;
using namespace std;

int main() {
	int n, a, k = 0, m = 0;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a != arr[i] && a==1) {
			m++;
		}
		else if (a != arr[i] && a == 0) {
			k++;
		}
	}
	if (k == 0) {
		cout << -1;
		return 0;
	}
	int t = (m + 1) / k;
	if (k * t < m + 1) {
		cout << t + 1;
		return 0;
	}
	cout << t;
}