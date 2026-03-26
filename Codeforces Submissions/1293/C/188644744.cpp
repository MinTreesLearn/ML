#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e8;
int mod = 1e9+7;
const int N = 2e5+5;
const int p = 998244353;


void solve(){
    int n, q;
    cin>>n>>q;

    set<pair<int, int>> s;
    int cnt = 0;
    while(q--){
        int x, y;
        cin>>x>>y;

        int con = 0;
        if(x==1){
            if(s.count({2, y}))con++;
            if(s.count({2, y-1}))con++;
            if(s.count({2, y+1}))con++;
        }else{
            if(s.count({1, y}))con++;
            if(s.count({1, y-1}))con++;
            if(s.count({1, y+1}))con++;
        }

        if(s.count({x, y}) && con){
            s.erase({x, y});
            cnt-=con;
        }else if(s.count({x, y})){
            s.erase({x, y});
        }else if(con){
            s.insert({x, y});
            cnt+=con;
        }else{
            s.insert({x, y});
        }

        if(!cnt){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed<<setprecision(20);
    int testCase = 1;
    //cin>>testCase;

    while(testCase--){
        solve();
    }
    return 0;
}