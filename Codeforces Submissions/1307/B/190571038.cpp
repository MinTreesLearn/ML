#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <valarray>
#include <set>
#include <unordered_set>
#include <ctime>
#include <iomanip>
#include <map>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define ull unsigned long long
#define ssp system("PAUSE")
#define fi first
#define se second
#define all(x) x.begin(),x.end()

using namespace std;

void solution()
{
	ll i, n, x;
	cin >> n >> x;
	vector <ll> R(n);

	for (i = 0; i < n; i++) {
		cin >> R[i];
	}

	sort(all(R));
	if (binary_search(all(R), x)) {
		cout << "1\n";
		return;
	}

	if (x - 2 * R[n - 1] <= 0) {
		cout << "2\n";
        return;
	}

	cout << ((x - 2 * R[n - 1]) / R[n - 1]) + 2 + ((x - 2 * R[n - 1]) % R[n - 1] != 0) << endl;
}

int main()
{
	int t; cin >> t;
	while (t--) solution();
	ssp;
}