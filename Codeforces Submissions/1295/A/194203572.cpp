#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
#define endl '\n';

void solve()
{
    int n; cin >> n;
    if (n % 2 != 0)
    {
        cout << "7";
        n -= 3;
    }
    
    while (n)
    {
        cout << 1;
        n -= 2;
    }
    cout << "\n";
}
		
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}