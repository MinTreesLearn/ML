#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
typedef  long long int ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	ll maxx = -500000;
	vector<ll>arr(n);
	vector<ll>arr1(1000000);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > maxx) {
			maxx = arr[i];
		}
	}
	ll a;
	for (int i = 0; i < n; i++) {
		a = arr[i] - i + 1;
		arr1[a+500000] += arr[i];
	}
	a = -500000;
	for (int i = 0; i < 1000000; i++) {
		if (arr1[i] > a) {
			a = arr1[i];
		}
	}
	cout << a;
}