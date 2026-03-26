#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define l "\n"
#define mod 100000009;
#define L_M LLONG_MAX
typedef unsigned long long ull;
#define all(v)          v.begin(),v.end()
ll gcd(ll a, ll b) { return(!b) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void Naked_Compiler()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
#endif
}
#define lpr pair<ll,ll>
bool comparefn(lpr a, lpr b)
{
    if (a.second != b.second)
        return a.first < b.first;
    return a.second < b.second;
}
const int N =10000;
int main() {
    Naked_Compiler();
    int tst; cin >> tst;
    while (tst--) {
        int n, cnt = 0; string s; cin >> n >> s;
        while (true) {
            bool ch = false;
            for (int i = 0; i < n; i++)
            {
                if (i == n - 1)break;
                if (s[i] == 'A' && s[i + 1] == 'P') {
                    s[i + 1] = 'A';
                    i++;
                    ch = true;
                }
            }
            cnt++;
            if (!ch)break;
        }
        cout << cnt - 1 << l;
    }
}
		  	  	 	 		 		 	 			 		 	 	