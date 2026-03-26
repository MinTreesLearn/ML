#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
typedef long long int ll;
#define MAX 100001
#include <map>
const int MOD = 1e9 + 7;
const ll MaxVal = 2e18; 
string PI = "314159265358979323846264338327";
map<ll, ll> freq;
vector<ll> power2;
vector<ll> pf;
vector<bool> prime(1000001, true);

int x[9] = {1, 1, 1, -1, -1, -1, 0, 0, 0};
int y[9] = {-1, 1, 0, -1, 1, 0, -1, 1, 0};
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    set<int> s;
    for (int& x: v){
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << '\n';    
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // for (ll q = 1;q<=MaxVal; q*=2){
    //     power2.push_back(q);
    // }
    // pf.resize(power2.size());
    // pf[0] = power2[0];
    // for (int i=1; i<power2.size(); i++) pf[i] = pf[i - 1] + power2[i];
    int t;
    // t = 1;
    cin >> t;       
    while (t--) solve();    
}    
 