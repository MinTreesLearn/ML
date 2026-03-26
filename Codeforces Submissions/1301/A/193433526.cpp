#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define range(i, n) for(int i = 0; i < (n); ++i)
#define rangex(i, n, x) for(int i = x; i <= (n); ++i)
#define vcin(a) for (auto &i : a) cin >> i
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;
void solve(){
    string a,b,c;
    cin >> a >> b >> c;
    range(i,a.size()){
        if(a[i]==c[i] or b[i]==c[i]) continue;
        no;
        return;
    }
    yes;
}
/*

*/
int main(int argc, char **argv) 
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;cin >> t;while(t--) 
    solve();
    return 0;
}