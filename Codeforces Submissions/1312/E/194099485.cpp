// https://codeforces.com/problemset/problem/1366/E
//https://codeforces.com/problemset/problem/1312/E
//	https://codeforces.com/problemset/problem/1409/F
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <math.h>
#include <vector>

using namespace std;
#define what(a) cerr << (#a) << " is " << (a) << '\n';

const int N = 505;

int memo1[N][N] , memo2[N][N] , n , a[N];

int dp1(int l , int r) {
	
	if(l == r) {
		return a[l];
	}

	if(l > r) return -1;

	int &res = memo1[l][r];
	if(res != -2) return res;

	res = -1;
		
	for(int i = l + 1 ; i <= r ; i++) {
		if(dp1(l , i - 1) == dp1(i , r) && dp1(l , i - 1) != -1) {
			res = dp1(l , i - 1) + 1;
		}
	}

	return res;
}

int dp2(int i , int last) {

	if(i == n + 1) {
		if(last == n + 1) return 0;
		return 1e9;
	}

	int &res = memo2[i][last];
	if(res != -2) return res;

	res = 1e9;

	res = min(res , dp2(i + 1 , last));

	if(dp1(last , i) != -1)
		res = min(res , 1 + dp2(i + 1 , i + 1));

	return res;
}

void solve() {

	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < N ; j++) memo1[i][j] = memo2[i][j] = -2;

	cout << dp2(1 , 1);

	return;
}


int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tt = 1;
  // cin >> tt;

  while (tt--) {
    solve();
  }
  return 0;
}
