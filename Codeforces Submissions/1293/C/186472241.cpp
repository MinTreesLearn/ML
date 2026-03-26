#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0);
void update(vector<vi> &a,int &cur,int i,int j){
    if(a[i][j]==0){
        if(a[(i+1)%2][j]==1) cur++;
        if(a[(i+1)%2][j-1]==1) cur++;
        if(a[(i+1)%2][j+1]==1) cur++;
        a[i][j]=1;
    }
    else{
        if(a[(i+1)%2][j]==1) cur--;
        if(a[(i+1)%2][j-1]==1) cur--;
        if(a[(i+1)%2][j+1]==1) cur--;
        a[i][j]=0;  
    }
}

int32_t main()
{
    fastio;
    int n,q,cur=0;
    cin>>n>>q;
    vector<vi> a(3,vi(n+2,0));
    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        update(a,cur,x,y);
        if(cur==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
return 0;
}