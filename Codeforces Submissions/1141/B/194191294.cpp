#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
#define endl '\n';

void solve()
{
	int n; cin>>n;
    vector<int> v(n);

    for (auto &it : v)
    {
        cin >>it;
    }

    int maxi = 0;
    int result = 0;

    for (int i = 0; i < 2*n; i++)
    {
        if (v[i%n] == 1)
        {
            maxi++;
            result = max(result,maxi);
        }
        else
        {
            maxi = 0;
        }   
    }

    cout<<result;
}
		
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	solve();
	return 0;
}