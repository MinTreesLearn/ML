/*
 *  Solution author: Mahmud-Sayed
 *  while(days) keep_going();
 */
#include <bits/stdc++.h>
using namespace std;
#define GO_FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC int TT;cin >> TT;while(TT--)
#define el '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin() , v.rend()
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int , int>> vpii;
typedef map<string , int> mpsi;
typedef map<int , int> mpii;
typedef map<int , string> mpis;
typedef map<int , char> mpic;
typedef map<char, int> mpci;
const int N = 2e5 + 6;
int a[N], ans[N];

int main(){
    GO_FASTER
    TC {
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a, a + 2*n);
        cout << a[n] - a[n - 1] << el;
    }
    return 0;
}
