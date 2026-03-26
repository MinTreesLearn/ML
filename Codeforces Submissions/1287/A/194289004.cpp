/*                                                     لا اله الا الله محمد رسول الله                                              */
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "Debug.cpp"
#else
#define debug(...) 1
#define Time(i, x...) x
#endif

using namespace std;
#define sad ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define all(x) x.begin(), x.end()
#define LL  long long
#define int LL
#define ld long double
#define un unsigned
#define Test unsigned int TC; cin >> TC; while(TC--)
#define sz(s) int(s.size())
#define NO cout<<"NO";
#define YES cout<<"YES";
#define FILE freopen("Input.txt", "r", stdin);
set<int>ans;
void fun() {
    for (int i = 1; i < 10001; ++i) {
        ans.insert(i*i*i);
    }
}
void Solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    bool x = 1;
    while (x){
        bool y = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 'A' && s[i+1] == 'P')
            s[i+1] = 'A', y = 1, i++;
    }
        if (!y)x = !x;
        c++;
    }
    cout << c-1;
}

signed main() {
    sad;
//    FILE
    Test
    Solve(), cout << el;
}
