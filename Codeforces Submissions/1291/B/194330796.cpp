#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
#define f11r(a, b) for (long long a = b-1; a >= 0; --a)
#define mp make_pair
void ELZOZ(){ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);}

//ابدا بالصلاه ع النبي اللهم صلي وسلم علي سيدنا محمد
//-----START-----//
void solve()
{
        int n, x ,y;
        cin >> n;
        vv arr(n);
        f0r(i, n) cin >> arr[i];
        f0r(i, n) {
            if (arr[i] >= i) x = i;
            else break;
        }
        f11r(i, n) {
            if (arr[i] >= n - 1 - i) y = i;
            else break;
        }
        if (y > x && n != 1) cout << "NO" eeq
        else cout << "YES" eeq

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





			  				 	 	  		  			 					 		