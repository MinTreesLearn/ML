//#include<bits/stdc++.h>

#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<iomanip>
#include <cstring>
#include<string>
#include<queue>
#include<deque>
#include <numeric>

//#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define forn(i, n) for(long long i = 0; i<(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vec(n)  vector <ll>a(n);
#define endl "\n"
#define sz size()
const int N = 2e5 + 20, M = 1000 + 7;
const int mod = 1e9 + 7;
int cr[] = { 0, 0, -1, 1 };
int cc[] = { -1, 1, 0, 0 };

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
#define isON(n,k) ((((n)>>k))&1)
#define ll long long
#define no cout << "NO\n"
#define yes cout << "YES\n"
//log10(n) + 1 = size n


ll summation(int n) {
    return ((n * (n + 1)) / 2);
}

void solve() {

    int n,q; cin >> n>>q;
    // 2 sets 1 2
    // 2 maps 1 2
    map<int, int>mp1, mp2;
    int cnt = 0;


    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == 1) {
            if (mp1[r]&& (mp2[r]||mp2[r + 1] || mp2[r - 1])) {

              //  cout << mp2[r] << "   " << mp2[r+1] << "  " << mp2[r-1] << endl;
              //  cout << "if1  " << l << "  " << r <<"  " << cnt << endl;
                if (mp2[r])
                    cnt--;
                if (mp2[r - 1])
                    cnt--;
                if (mp2[r + 1])
                    cnt--;
                mp1[r] = 0;

            }
            else if (mp2[r] || mp2[r + 1] || mp2[r - 1]) {
             //  cout << mp2[r] << "   " << mp2[r + 1] << "  " << mp2[r - 1] << endl;
              //  cout << "if2  " << l << "  " << r << "  " << cnt << endl;
                if (mp2[r])
                    cnt++;
                if (mp2[r - 1])
                    cnt++;
                if (mp2[r+1])
                    cnt++;
                mp1[r] = 1;
            }
            else {
              //  cout << mp2[r] << "   " << mp2[r + 1] << "  " << mp2[r - 1] << endl;
               // cout << "if3  " << l << "  " << r << "  " << cnt << endl;
                if (mp1[r])mp1[r] = 0;
                else  mp1[r] = 1;

            }

        }
        else {
            if (mp2[r]&& (mp1[r]||mp1[r + 1] || mp1[r - 1])) {
              //  cout << mp1[r] << "   " << mp1[r + 1] << "  " << mp1[r - 1] << endl;
               // cout << "if14  " << l << "  " << r << "  " << cnt << endl;
                if (mp1[r])
                    cnt--;
                 if (mp1[r - 1])
                    cnt--;
                 if (mp1[r + 1])
                    cnt--;
                mp2[r] = 0;
            }
            else if (mp1[r] || mp1[r + 1] || mp1[r - 1]) {
              //  cout << mp1[r] << "   " << mp1[r + 1] << "  " << mp1[r - 1] << endl;
              //  cout << "if15  " << l << "  " << r << "  " << cnt << endl;
                if (mp1[r])
                    cnt++;
                if (mp1[r - 1])
                    cnt++;
                if (mp1[r + 1])
                    cnt++;
                mp2[r] = 1;
            }
            else {
               // cout << mp1[r] << "   " << mp1[r + 1] << "  " << mp1[r - 1] << endl;
                //cout << "if16  " << l << "  " << r << "  " << cnt << endl;
                if (mp2[r])mp2[r] = 0;
                else  mp2[r] = 1;

            }
        }
       // cout << cnt << endl;
        if (cnt > 0)no;
        else yes;
    }
}

int t = 1;
int main() {
    fast();
    //freopen("mex.in" ,"r" ,stdin);
   //freopen("output.txt" ,"w" ,stdout);

    //cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}

