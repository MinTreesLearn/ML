#include <bits/stdc++.h>
using namespace std;
/*-----------------*/
#define ll long long
#define ld long double
#define ever (;;)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define PB push_back
#define F first
#define S second
#define MOD 1000000007
#define Dracarys ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//string binary=bitset<8>(n).to_string();

const int N = 1e5 + 10;

int n, h, l, r;
vector<int>v;
int DP[2001][2001];
bool check(int num) { return (num >= l && num <= r); }
int Dp(int i, int Time)
{
    if (i == n)
        return 0;
    int& ret = DP[i][Time];
    if (ret != -1)
        return ret;
    int val1 = (Time + v[i]) % h;
    int val2 = (Time + v[i] - 1) % h;
    int Ans1, Ans2;
    if (check(val1))
        Ans1 = Dp(i + 1, val1) + 1;
    if (!check(val1))
        Ans1 = Dp(i + 1, val1);
    if (check(val2))
        Ans2 = Dp(i + 1, val2) + 1;
    if (!check(val2))
        Ans2 = Dp(i + 1, val2);
    return ret = max(Ans1, Ans2);
}
void OverFlow()
{
    cin >> n >> h >> l >> r;
    v.resize(n);
    for (auto& it : v)cin >> it;
    memset(DP, -1, sizeof(DP));
    cout << Dp(0, 0);
}

int main()
{
    Dracarys
    int t = 1;
    //cin >> t;
    while (t--)
    {
        OverFlow();
    }
    return 0;
}
