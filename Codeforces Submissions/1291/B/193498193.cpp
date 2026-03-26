#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {
	    int n; cin >> n;
	    vector<int> fin(n);

	    for (int i = 0; i < n; ++i)
		    cin >> fin[i];

	    int pref_num = -1, suff_num = n;

	    for (int i = 0; i < n; ++i) {
		    if (fin[i] < i) break;
		    pref_num = i;
	    }
	    for (int i = n-1; i >= 0; --i) {
		    if (fin[i] < (n-1)-i) break;
		    suff_num = i;
	    }

	    if (suff_num <= pref_num) // Non-empty intersection
		    cout << "Yes\n";
	    else
		    cout << "No\n";
    }
}
