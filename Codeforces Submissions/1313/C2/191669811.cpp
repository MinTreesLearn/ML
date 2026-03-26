#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1e6;
long long n, m, a[N], sumL[N], sumR[N];
void solve() {
    stack<long long> L, R;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (!L.empty() && a[L.top()] > a[i]) {
            L.pop();
        }
        if (!L.empty())
            sumL[i] = sumL[L.top()] + (i - L.top()) * a[i];
        else
            sumL[i] = sumL[0] + i * a[i];
        L.push(i);
    }
    long long t, s = 0;
    for (int i = n; i >= 1; i--) {
        while (!R.empty() && a[i] < a[R.top()]) {
            R.pop();
        }
        if (!R.empty())
            sumR[i] = sumR[R.top()] + (R.top() - i) * a[i];
        else
            sumR[i] = sumR[n + 1] + (n + 1 - i) * a[i];
        R.push(i);
        if (sumL[i] + sumR[i] - a[i] > s) {
            s = sumL[i] + sumR[i] - a[i];
            t = i;
        }
    }
    for (int i = t - 1; i > 0; i--) {
        if (a[i] > a[i + 1]) a[i] = a[i + 1];
    }
    for (int i = t + 1; i <= n; i++) {
        if (a[i] > a[i - 1]) a[i] = a[i - 1];
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
		 			  	 	 		   	    		 	