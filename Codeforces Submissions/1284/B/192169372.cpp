//
// Created by ahmed-kashkoush on 2/4/23.
//
//والله يابني مانا عارف ادينا بنهبد
//كود بلا هدف, تكبييييير
// Problem Link -->
/**symbols
    @!  --> important and and write it down
*/
#include<bits/stdc++.h>

#define el '\n'
#define ll long long
#define reset(v, d) memset(v, d , sizeof(v))
#define all(s)  s.begin(), s.end()
#define cin(v)  for(auto &i:v)cin>>i
#define cout(v) for(auto i:v)cout<<i<<" "
using namespace std;
void judge();void tc();
const ll  OO=INT_MAX;


void solve() {
    int n; cin>>n;
    vector<pair<int, int>> pr;// pair of[min, max]
    for(int i=0;i<n;i++){
        int m; cin>>m;
        vector<int> v(m);
        cin(v);
        reverse(all(v));
        if(is_sorted(all(v)))
            pr.emplace_back(v[0], v[m-1]);
        // he stored what can't form
    }
    sort(all(pr));
    ll ans=(ll)n*n;
    // he removed what can't fomr
    for(auto [mn, mx]:pr){
        ans-=pr.end()-lower_bound(all(pr), make_pair(mx,-1));
        // means to remove only the vectors that have min greater than my mx
    }
    cout<<ans;

}

int main() {
    judge();
//    tc();
    solve();
    return 0;
}
void tc(){
    int t = 1;
      cin>>t;
    for (int tc = 1; tc <= t; tc++) {
        cout<<"#tc"<< tc<<": ";
        solve();
        //    cout<<endl;
        cout<<el;
    }
}
void judge() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
