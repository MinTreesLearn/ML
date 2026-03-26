#include<bits/stdc++.h>

using namespace std;
 
#define all(x) x.begin() , x.end()
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define pb push_back
#define qb pop_back
#define F first
#define S second
#define wall cerr<<"--------------------------------------"<<endl
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef double db;
 
const ll INF = 1e9;
const ll maxn = 4e3 + 10;
const ll mod = 1e9 + 7;

ll t , n , m , k , a[maxn] , b[maxn] , x , y , z , ans;
string s;
vector<ll> ve;
set<ll> se;

int main()
{
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
        cin>>t;
        while(t--){
                cin>>n>>m>>k;
                k = min(k , m-1);
                for(int i=1; i<=n; i++){
                        cin>>a[i];
                }ans = -1;
                for(int len=0; len<=k; len++){
                        int l = len+1 , r = n+len-k;
                        x = INF;
                        //cout<<l<<"_"<<r<<" => "<<len<<" : ";
                        int rem = m - k - 1;
                        for(int i=0; i<=rem; i++){
                                ll y = max(a[l+i] , a[r+i-rem]);
                                
                                //cout<<y<<" ";
                                
                                x = min(x , y);
                        }

                        //cout<<endl;
                        
                        ans = max(ans , x);
                }
                cout<<ans<<endl;
                wall;
        }
        return 0;
}
/*
by
                        .         .--. .--. .--.
                      .'|         |__| |__| |__|
                     <  |         .--. .--. .--.
    __                | |         |  | |  | |  |
 .:--.'.          _   | | .'''-.  |  | |  | |  |
/ |   \ |       .' |  | |/.'''. \ |  | |  | |  |
`" __ | |      .   | /|  /    | | |  | |  | |  |
 .'.''| |    .'.'| |//| |     | | |__| |__| |__|
/ /   | |_ .'.'.-'  / | |     | |
\ \._,\ '/ .'   \_.'  | '.    | '.
 --'  "             '---'   '---
 
*/