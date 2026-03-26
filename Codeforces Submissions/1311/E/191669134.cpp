#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
constexpr int N = int(4e2) + 5;
constexpr int inf = 0x7f7f7f7f;
constexpr int MOD = int(1e9) + 7;

void solve(){
    int n, d;
    cin >> n >> d;

    if(n * (n - 1) / 2 < d){
        cout << "NO\n";
        return;
    }
    n--;
    vector<int> v = {1};
    while(n){
        d -= min(n, v.back() * 2) * v.size();
        v.push_back(min(n, v.back() * 2));
        n -= v.back();
    }
    if(0 > d){
        cout << "NO\n";
        return;
    }
    while(d){
        if(v.back() > 1) v.push_back(0);
        for(int i = v.size() - 1; i && v[i - 1] != 1 && d; i--){
            while(d && 2 * (v[i - 1] - 1) >= v[i] + 1){
                v[i]++;
                v[i - 1]--;
                d--;
            }
        }
    }
    cout << "YES\n";
    //for(auto& i : v) cout << i << ' ';
    vector<vector<int>> v2(v.size());
    for(int i = 0, j = 1; i < v.size(); i++){
        while(v[i] > v2[i].size()){
            v2[i].push_back(j++);
        }
    }
    for(int i = 1; i < v.size(); i++){
        for(int j = 0; j < v2[i].size(); j++){
            cout << v2[i - 1][j >> 1] << ' ';
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0);    
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
   				  		       	    			 				