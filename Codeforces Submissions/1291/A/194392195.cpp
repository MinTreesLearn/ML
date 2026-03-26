#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
#define endl '\n';

void solve()
{
	int n; cin>>n;
    string s; cin>>s;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if ((s[i]-'1')%2==0)
        {
            c++;
        }
    }

    if (c>1)
    {
        int a = 2;
        for (int i = 0; i < n; i++)
        {
            if ((s[i]-'1')%2==0 && a!=0)
            {
                cout<<s[i];
                a--;
            }       
        }
    }
    else
    {
        cout<<-1;
    }
    cout<<endl;
    
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