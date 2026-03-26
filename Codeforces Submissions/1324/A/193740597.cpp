#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
#define yes yes();
#define no no();
#define endl '\n';

void solve()
{
	int n; cin>>n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int temp; cin>>temp;
        st.insert(temp%2);
    }

    if (st.size()>1) no
    else yes;

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