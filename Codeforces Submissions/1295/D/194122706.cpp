#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll GCD(ll x, ll y)
{
    return y ? GCD(y, x % y) : x;
}

int main()
{
    int T;  cin >> T;

    while(T--)
    {
        ll a, m;    cin >> a >> m;

        vector <ll> Div;

        for(ll x = 1; x * x <= m; x++)
        {
            if(m % x == 0)
            {
                Div.push_back(x);

                if(x * x != m)  Div.push_back(m / x);
            }
        }

        sort(Div.begin(), Div.end(), greater <ll> ());

        vector <ll> Dp(Div.size());

        ll L = a - 1;
        ll R = a + m - 1;

        ll Ans = 0;
        ll G = GCD(a, m);

        for(int i = 0; i < Div.size(); i++)
        {
            ll x = Div[i];

            Dp[i] = R / x - L / x;

            for(int j = 0; j < i; j++)
                if(Div[j] % Div[i] == 0)
                    Dp[i] -= Dp[j];
            if(Div[i]==G)
            {
                Ans = Dp[i];
                break;
            }
        }


        // for(int i = 0; i < Div.size(); i++)
        // {
        //     ll x = Div[i];

        //     if(x == G)
        //     {
        //         Ans = Dp[i];
        //         break;
        //     }
        // }

        cout << Ans << endl;
    }
}
