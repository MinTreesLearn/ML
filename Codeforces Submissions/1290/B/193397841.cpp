#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <cstdio>
#include <ctime>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define lg log10
#define re register
#define db double
#define ld long double
#define ll long long
#define ull unsigned long long
#define nth nth_element
#define lb lower_bound
#define ub upper_bound
#define _div stable_partition
#define _merge inplace_merge
#define point(x) setiosflags(ios::fixed)<<setprecision(x)
#define writen(x) write(x),printf("\n")
#define writet(x) write(x),printf(" ")
//const ull MOD = 212370440130137957ll;
const ll MOD = 1e9 + 7;
int test = 1;
//读入输出优化
namespace Fio {
    inline string sread() {
        string s = " "; char e = getchar();
        while (e == ' ' || e == '\n') e = getchar();
        while (e != ' ' && e != '\n') s += e, e = getchar();
        return s;
    }
    inline ll read() {
        ll x = 0, y = 1; char c = getchar();
        while (!isdigit(c)) { if (c == '-') y = -1; c = getchar(); }
        while (isdigit(c)) { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
        return x *= y;
    }
    inline void write(ll x) {
        if (x < 0)x = -x, putchar('-'); ll sta[35], top = 0;
        do sta[top++] = x % 10, x /= 10; while (x);
        while (top) putchar(sta[--top] + '0');
    }
} using namespace Fio;
const ll modd = 998244353;
const ll inv2 = 499122177;
const ll inv6 = 166374059;
const ld eps = 0.000001;
mt19937 rnd(time(0));


ll q, n, s[26][200005];
inline ll check(ll l, ll r) {
    ll res = 0;
    for (ll i = 0; i < 26; ++i)
        res += (s[i][r] - s[i][l - 1] > 0);
    return res >= 3;
}
inline void qfl_zzz() {
    string a = sread();
    ll n = a.size() - 1;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 0; j < 26; ++j)
            s[j][i] = s[j][i - 1] + (a[i] - 'a' == j);
    q = read();
    while (q--) {
        ll l = read(), r = read();
        if (l == r || a[l] != a[r] || check(l, r)) printf("Yes\n");
        else printf("No\n");
    }
}
inline void pre_work() {
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    srand((unsigned)time(0));
    //test = read();
    //cin >> test;
    pre_work();
    while (test--) qfl_zzz();
    return 0;
}