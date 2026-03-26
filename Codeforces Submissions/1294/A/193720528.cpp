#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		int maxt = -1;
		maxt = max(a, max(b, c));
		int s = a + b + c + n;
		if (s % 3 == 0 and s / 3 >= maxt) {
			cout << "Yes" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;


}
