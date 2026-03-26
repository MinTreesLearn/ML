#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1e9 + 7

void solve(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> res(n);
    int unused = n, start = 0;
    for(int i=0; i<n; ++i){
        if(i == n - 1 || s[i] == '>'){
            for(int j=i; j>=start; --j){
                res[j] = unused;
                unused--;
            }
            start = i + 1;
        }
    }

    for(int i=0; i<n; ++i){
        cout << res[i] << (i == n - 1? "\n": " ");
    }

    unused = 1, start = 0;
    for(int i=0; i<n; ++i){
        if(i == n - 1 || s[i] == '<'){
            for(int j=i; j>=start; --j){
                res[j] = unused;
                unused++;
            }
            start = i + 1;
        }
    }

    for(int i=0; i<n; ++i){
        cout << res[i] << (i == n - 1? "\n": " ");
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
