#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define    rep(X,Y)     for(X=0;X<Y;X++)
#define    rep1(X,Y)    for(X=1;X<=Y;X++)
#define ml ll T,g; cin>>T; for(g=0;g<T;g++)
#define nml ll T = 1,g; for(g=0;g<T;g++)
#define pb push_back
#define pll pair<ll , ll>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i, j;
  ml {
    ll n , k , x = 0;
    cin >> n >> k;
    map<ll, ll>mp;
    for(i= 0 ; i<=100;i++)
    {
      mp[i] = 0;
    }
    rep(i , n)
    {
      ll a;
      cin >> a;
      ll cnt = 0;
      while (a)
      {
        ll b = a % k;
        mp[cnt] += b;
        cnt++;
        a /= k;

      }
    }
    for (auto it : mp)
    {
      if (it.second > 1)
      {
        x = 1;
        break;
      }
    }
    if (x)cout << "NO" << endl;
    else cout << "YES" << endl;
  }

  return 0;
}