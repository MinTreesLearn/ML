#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define ld long double
#define vv vector<ll>
#define T ll ttt;cin>>ttt;while(ttt--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mod 1000000007
#define pb emplace_back
#define eeq <<"\n";
#define PI 3.14159265359
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b) for (long long a = 1; a <= (b); ++a)
#define f11r(a, b) for (long long a = b-1; a > 0; --a)
#define mp make_pair
void ELZOZ(){ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);}

//ابدا بالصلاه ع النبي اللهم صلي وسلم علي سيدنا محمد
//-----START-----//
void solve()
{
        ll n, m;
        cin >> n >> m;
        ll arr1[n];
        map<ll, ll> freq;
        f0r(i, n) cin >> arr1[i];
        f0r(i, m)
        {
            ll a;
            cin >> a;
            freq[a]++;
        }
        f0r(i, n)
        {
            f0r(j, n - 1)
            {
                if (arr1[j] > arr1[j + 1])
                {
                    if (!freq[j + 1]) break;
                    else swap(arr1[j], arr1[j + 1]);
                }
            }
        }
        if (is_sorted(arr1, arr1 + n)) cout << "YES" eeq
        else cout << "NO" eeq
}
int main()
{
//freopen("lazy.in", "r", stdin);
// memset(dp, -1, sizeof(dp));
    ELZOZ(); // <---*---*---*---*---*{*}****--0
    T{
    solve();
    }
}
	   			   			  		 					 	  		