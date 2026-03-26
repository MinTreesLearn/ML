#include <bits/stdc++.h>
#include<cmath>
#include <map>
using namespace std;
#define ll long long
#define lld long  double
#define sst string
#define freeopen   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define ios ios::sync_with_stdio(false);
#define pb push_back
#define foor(x,vec) for(auto x:vec ){cout<< x<<" ";};
#define fi first
#define se second
#define mod 1000000007
//
//int main(){
//    ll m,n,b,k;
//    cin>>m>>n>>b>>k;
//    ll mk=-111111111111;
//    ll x[169][169];
//    for(ll i=1;i<=m;i++){
//        for(ll j=1;j<=n;j++){
//            cin>>x[i][j];
//        }
//    }
//    ll sum=0,ans=0;
//    for(ll i=b;i<=m;i++){
//        for(ll j=k;(j<=n);j++){
//            sum=0;
//            for(ll h=i-b+1;h<=i;h++){
//                for(ll w=j-k+1;w<=j;w++){
//                    sum+=x[h][w];
//                }
//            }
//            mk=max(sum,mk);
//        }
//    }
//
//        for(ll j=k;j<=n;j++){
//            sum=0;
//            for(ll w=j-k+1;w<=j;w++){
//                sum+=x[m][w];
//                sum+=x[1][w];
//            }
//            mk=max(sum,mk);
//        }
//    for(ll j=b;j<=m;j++){
//        sum=0;
//        for(ll w=j-b+1;w<=j;w++){
//            sum+=x[w][n];
//            sum+=x[w][1];
//        }
//        mk=max(mk,sum);
//    }
//
//
////    for(ll i=)
//    cout<<mk;
//}
//
//
//
//
////int main(){
////    ll m,n,x[100069];
////    set <ll> st;
////    cin>>n>>m;
////    ll mk=mod;
////    for(ll i=1;i<=n;i++){
////        cin>>x[i];
////        mk=min(mk,x[i]);
////        st.insert(x[i]);
////    }
////
////    if(st.size()==m){
////        cout<<"-1";
////    }
////    else if(n==1){
////        if(m-x[1]>x[1]-1){
////            cout<<m;
////        }
////        else{
////            cout<<n;
////        }
////    }
////    else{
////        for(auto x : st){
////
////        }
////
////    }
////
////
////}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,x,y;
        cin>>a>>b>>x>>y;
        ll ans=max(max(x*b,y*a),max((a-1-x)*b,(b-1-y)*a));
        cout<<ans<<endl;
    }
}
