/*                                                     لا اله الا الله محمد رسول الله                                              */
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define sad cin.tie(0);cin.sync_with_stdio(0);
#define el "\n"
#define all(x) x.begin(), x.end()
#define ll  long long
#define Test unsigned ll TC; cin >> TC; while(TC--)
#define NO cout<<"NO\n";
#define YES cout<<"YES\n";
#define sz(s) int(s.size())

const ll MOD = 1e9 + 7;
ll n, m, p, q;

string tmp;
vector<string>v1,v2;
int main() {
    sad;;;;;;;;;;;;
cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v1.push_back(tmp);
    }
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        v2.push_back(tmp);
    }

    Test {
        cin >> p;p--;
        cout << v1[p % n] << v2[p % m] << el;
    };

}
/*
 * sinyu
imsul
gyehae
gapja
gyeongo
sinmi
imsin
gyeyu
gyeyu
byeongsin
jeongyu
musul
gihae
gyeongja
 */