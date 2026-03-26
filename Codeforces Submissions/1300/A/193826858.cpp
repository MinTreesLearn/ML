#include <bits/stdc++.h>
#define f first
#define S second
#define pb push_back
#define msk(x , y) (x >> y) & 1
#define all(x) x.begin() , x.end()      
using namespace std;
typedef long long int ll; 
const int N = 5e5 + 7 ;
const ll mod = 998244353;
const int dx[] = {-1, -1 , -1 , 0, 0 , -1 , 1 , 1};
const int dy[] = {-1 , 0 , 1 , -1, 1 , 1 , 0 , 1};

int n , m  ,a[N] , b , Mx;

void solve(){
    cin >> n ;
    int sum = 0 , mx = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(a[i] == 0) mx++;
        sum += a[i];
    }
    if(mx == 0){
        if(sum == 0) cout << "1\n";
        else cout << "0\n";
    }
    else{
    	if(sum + mx != 0) cout << mx << "\n";
    	else cout << mx + 1 << "\n";
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    cout.tie(0);
    int test = 1 ;
    cin >> test ;
    for(int i = 1; i <= test ; i++) {
//          cout << "Case " << i << ":\n";
        solve();
    }
}