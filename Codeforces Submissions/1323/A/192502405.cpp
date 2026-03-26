#include <bits/stdc++.h>
 
using namespace std;
 
 
#define A first
#define B second
#define MP make_pair
#define ms(a, x) memset(a, x, sizeof(a)) 
 
 
#define boost() ios_base::sync_with_stdio(false); cin.tie(); cout.tie()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pld;
const int INF = 0x3f3f3f3f;
 
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int mxN=1e4+5;



int main(){
    boost();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        if(n >= 2){
            int odd=-1;
            bool found=false;
            for(int i=0; i<n; i++){
                if(v[i]%2 == 0){
                    cout << 1 << '\n' << i+1;
                    found=true;
                    break;
                }
                if(odd == -1){
                    odd=i+1;
                }
                else{
                    cout << 2 << '\n' << odd << " " << i+1;
                    found=true;
                    break;
                }
            }
            if(!found) cout << -1;
        }
        else{
            if(v[0] % 2 == 0){
                cout << 1 << '\n' << 1;
            }
            else
                cout << -1;
        }
        cout << '\n';
    }
}
  	  		 					  	   		 	 	 				