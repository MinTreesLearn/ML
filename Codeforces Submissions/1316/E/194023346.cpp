#include <bits/stdc++.h>
#include <bit>
#include <bitset>
#include <cstdint>
#define all(v) v.begin() ,v.end()
#define ll long long
using namespace std ;
ll dp[100005][(1<<7)+5]  ;
vector<pair <int , int>>all ;
int n, p ,  k ;
int s[100005][7] ;

ll solve (int idx ,  int msk){
    int cnt  = idx-__builtin_popcount(msk) ;
     ll &ans  =  dp[idx][msk] ;

    if (idx==n){
        if (msk==((1<<p)-1))return ans =  0 ;
                       return ans = -1e15 ;
    }
    if (~ans)return ans  ;
        ans  = 0 ;
          if (cnt<k)
          ans = solve(idx+1  ,msk)+all[idx].first ;
        else ans = solve(idx+1 , msk) ;
       for (int i = 0 ; i < p ; i++){
        if ((msk&(1<<i))==0){
            ans =  max (ans , solve(idx+1 , (msk|(1<<i)))+ s[all[idx].second][i]) ;
        }
    }
    return ans  ;
}
void acc(){
   cin>>n >>p>>k ;
    for (int i =0 ; i <n ; i++){
      int x ;cin>>x;
      all.push_back({x,i}) ;
    }
    sort(all(all)) ;
    reverse(all(all)) ;
    for (int i =0 ; i < n ; i++){
        for (int j =0 ; j < p ; j++){
            cin >>s[i][j] ;
        }
    }
    memset(dp,-1 , sizeof dp) ;
    cout <<solve(0,0) ;

}
int main (){
    int t =1 ;
    //cin >>t;
    while (t--)acc() ;

}