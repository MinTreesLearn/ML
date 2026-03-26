

#include<bits/stdc++.h>

using namespace std;
#define ll long long 
const int N = 2e5 + 10;
#define PII pair<int,int >

int a[200];


void solve() {
 
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L')
            l++;
        else
            r++;
    }
    cout << r + l+1;
}

int main() {
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

