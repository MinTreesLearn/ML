#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define Y ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int N = 1e4 + 5;

int n, m, ans = -1;

void go(int res, int step) {
    if (res == m) ans = max(ans, step);
    if (res > m) return;
    go(res * 2, step + 1);
    go(res * 3, step + 1);
}

int main() {
    Y
    cin >> n >> m;
    go(n, 0);
    cout << ans;
    return 0;
}
	  		 								  		    	  				 	