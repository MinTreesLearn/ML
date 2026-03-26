#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Ta7a ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
// EL_MEXICY
using namespace std;

int main() {
    Ta7a;
    ll t = 1;
    cin >> t;
    while (t--) {
        string s;cin >>s;
        int cnt = 0,res = 0;
        if (s.size() == 1) {
            if (s[0] =='L')cout << "2\n";
            else cout << "1\n";
            continue;
        }
        if(s[0]=='L') res = 1;
        for (int i = s.size()-1; i > 0;i--){
            cnt = 0;
            while (s[i] == 'L'){
                cnt++;
                i--;
            }
            res = max(res,cnt);
        }
        cout << res+1 << '\n';
    }
}
