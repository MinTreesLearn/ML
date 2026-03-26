#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define pb       push_back
#define Sz(x)    int((x).size())
#define all(x)   x.begin(), x.end()
#define fi       first
#define se       second
#define cl       clear
 
const int maxn  =  1e6   + 10;
const int maxa  =  2e9   +  5;
const int mod   =  1e9   +  7;
const ll  inf   =  2e18;
const double eps = 1e-9;
 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, ans = 0;
    string s;
    cin >> n >> s;
    while (true){
        int j = -1;
        for (int i = 0; i < Sz(s); i ++){
            if((i && s[i - 1] == s[i] - 1) || (i != Sz(s) - 1 && s[i + 1] == s[i] - 1)){
                if(j == -1) j = i;
                else if(s[i] > s[j]) j = i;
            }
        }
        if(j == -1) break;
        string t;
        for (int i = 0; i < Sz(s); i ++) if(i != j) t += s[i];
        s = t;
        ans ++;
    }
    cout << ans << endl;
    return 0;
}