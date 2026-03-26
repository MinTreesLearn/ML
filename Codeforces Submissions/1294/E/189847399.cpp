#include<iostream>
#include <bits/stdc++.h>
using namespace std;
template<class container> void print(container v) { for (auto& it : v) cout << it << ' ' ;cout <<endl;}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define nd "\n"
#define all(x) (x).begin(), (x).end()
#define popcount(x)  __builtin_popcount(x)
const ll N = 2e5+50 , LOG = 22 , inf = 1e8 , SQ= 550 , mod = 1e9+7;
#define py cout <<"YES"<<endl;
#define pn cout <<"NO"<<endl;
#define pp  cout <<"ppppppppppppppppp"<<nd;
#define lol cout <<"i am here"<<nd;
const  double PI = acos(-1.0);

const int MX = 1000+10;


void hi(){
    int n , m; cin >> n >> m;
    vector<vector<ll> > a(n , vector <ll>(m));
    for (auto &i : a) for (auto &j : i) cin >> j , --j;
    ll ans = 0;
    for (int j = 0; j < m; ++j){
        vector <int > cnt(n);// the number of cycles needed to put the element in its position
        for (int i = 0;i < n; ++i){
            if (a[i][j] % m != j || a[i][j] /m >= n) continue;
            cnt[(i - a[i][j]/m +n) % n]++;
        }
        int cur = n - cnt[0];
        for (int i = 1; i < n; ++i) cur = min(cur , n-cnt[i]+i);
        ans+=cur;
    }
    cout << ans <<nd;
  


}

int main(){
     ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int tt = 1 , tc = 0;
  // cin >> tt;
    while(tt--) hi();
    return 0;
}

