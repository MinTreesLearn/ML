#include <bits/stdc++.h>
typedef long long ll;
#define vi     vector <int>
#define vll    vector <long long>
#define vs     vector <string>
#define vc     vector <char>
#define PII    pair<int,int>
#define MII    map<int,int>
#define UMII   unordered_map<int,int>
#define sz(v)  (int)v.size()
#define all(v) v.begin(),v.end()
#define ff     first 
#define ss     second 
#define int    long long
#define endl   "\n"
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;
const int  M  = 1e9+7;
const int  N  = 1e5+7;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        int n,q;
        cin >> n >> q;
        vector<vector<int>> v(2,vector<int>(n+1));
        int locks{};
        while(q--){
            int a,b; cin >> a >> b;
            a--; b--;
            if(v[a][b] == 0){
                v[a][b] = 1;
                locks += v[a^1][b];
                if(b-1 >= 0) locks += v[a^1][b-1];
                if(b+1 < n) locks += v[a^1][b+1];
            }else{
                v[a][b] = 0;
                locks -= v[a^1][b];
                if(b-1 >= 0) locks -= v[a^1][b-1];
                if(b+1 < n) locks -= v[a^1][b+1];
            }
            if(!locks){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }
        }
    return 0;
}
