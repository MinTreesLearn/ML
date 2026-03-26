#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ull unsigned long long
#define ld long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define in freopen ("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);

using namespace std;

const ll INF = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 33;
const ld eps = 1e-14;
const ld pi = acos(-1);

ll test = 1;
ll mx = inf, mn = INF, sum, res, pos, save;
string s;
ll r;

void solve()
{
    ll n;
    cin >> n;
    cin >> s;
    pos = -1;
    for(int i = 0;i < s.size();i ++)
    {
        if(s[i] == '(') r++;
        if(s[i] == ')') r--;
        if(r < 0 && pos == -1)
            pos = i;
        else if(r >= 0)
        {
            if(pos != -1)
            {
                res += i - pos + 1;
                pos = -1;
                r = 0;
            }
        }
    }
    if(r != 0)
    {
        cout << -1;
    }
    else
    {
        cout << res;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    //cin >> test;
    while(test --)
    {
        solve();
        cout << '\n';
    }
}
