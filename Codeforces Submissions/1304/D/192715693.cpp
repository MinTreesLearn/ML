
// Author : حسن

#include <bits/stdc++.h>
using namespace std;

#define TL ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define rall(s) s.rbegin(),s.rend()
#define all(s) s.begin(),s.end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"

const int N = 4e5 + 9 , mod = 1e9 + 7;
ll a[N] , us[N] = {} , d[N] = {} , dp[N] = {} , b[N] = {} , c[N] = {} ,  p[N] = {} ;

void solve(){
ll   q , s = 0, n , f , l , r , i , j  , mn = 1e9 + 20, mx = 0, x , y ,  m  , k;
cin>>n;
string a;
cin>>a;
for(i = 1; i <= n; i++){
    b[i] = i;
    c[i] = n - i + 1;
}
l = 0;
l = 1e9;

for(i = 0; i < a.size(); i++){
    if(a[i] == '>'){
        l = min(l , i);
    }else {
        if(l != 1e9){
            x = i + 1;
            y = l + 1;
            for(j = i + 1; j >= l + 1; j--){
                if(x >= y){
                    swap(b[x] , b[y]);
                }else {
                break;
                }
                x--;
                y++;
            }
        }
        l = 1e9;
    }
}
if(l != 1e9){
    x = a.size() + 1;
    y = l + 1;
    for(j = a.size() + 1; j >= l + 1; j--){
        if(x >= y){
            swap(b[x] , b[y]);
        }else {
            break;
        }
        x--;
        y++;
    }
}
l = 1e9;
for(i = 0; i < a.size(); i++){
    if(a[i] == '<'){
        l = min(l , i);
    }else {
        if(l != 1e9){
            x = i + 1;
            y = l + 1;
            for(j = i + 1; j >= l + 1; j--){
                if(x >= y){
                    swap(c[x] , c[y]);
                }else {
                break;
                }
                x--;
                y++;
            }
        }
        l = 1e9;
    }
}
if(l != 1e9){
    x = a.size() + 1;
    y = l + 1;
    for(j = a.size() + 1; j >= l + 1; j--){
        if(x >= y){
            swap(c[x] , c[y]);
        }else {
            break;
        }
        x--;
        y++;
    }
}
for(i = 1; i <= n; i++)
    cout<<c[i]<<" ";
cout<<"\n";
for(i = 1; i <= n; i++)
    cout<<b[i]<<" ";
cout<<"\n";
}

int main(){
     TL;
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
int t = 1;
cin>>t;
while(t--)
     {
     solve();
     }

}
// Author : حسن
