#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

int t, n, m, k, a[1000005], mod = 1e9 + 7;
mt19937_64 rng;
map<vector<int>, int> mp;
vector<int> ans[100005];
int mul(int x, int y){
    if(y == 0) return 1;
    int ans = mul(x, y / 2);
    if(y % 2 == 0) return (ans * ans) % mod;
    else return (((ans * ans) % mod) * x) % mod;
}

void solve(){
    if(n == 1){
        cout << "? " << 1 <<" "<< n << endl;
        string s; cin >> s;
        cout << "! " << s << endl; return;
    }
    cout << "? " << 1 <<" "<< n << endl;
    for(int i = 1; i <= n * (n + 1) / 2; i++){
        string s; cin >> s; 
        int sz = s.size();
        vector<int> v(26);
        for(int j = 0; j < sz; j++) v[s[j] - 97]++;
        mp[v]++;
    }
    cout << "? " << 2 <<" "<< n << endl;
    for(int i = 1; i <= n * (n - 1) / 2; i++){
        string s; cin >> s; 
        int sz = s.size();
        vector<int> v(26);
        for(int j = 0; j < sz; j++) v[s[j] - 97]++;
        mp[v]--;
    }
    for(auto i: mp){
        if(i.se){
            int sum = 0;
            for(auto j: i.fi) sum += j;
            ans[sum] = i.fi;
        }
    }
    cout << "! ";
    ans[0].assign(26, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++){
            if(ans[i][j] > ans[i - 1][j]){
                cout << char(j + 97);
            }
        }
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    rng.seed((int)main ^ time(0));
    #ifdef Kawaii
        auto starttime = chrono::high_resolution_clock::now();
    #endif

    cin >> n;
    solve();

    #ifdef Kawaii
        auto endtime = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(endtime - starttime).count(); 
        cout << "\n=====" << "\nUsed: " << duration << " ms\n";
    #endif
}