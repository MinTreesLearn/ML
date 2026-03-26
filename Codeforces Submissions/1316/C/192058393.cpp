//______________"In The Name Of GOD"______________

#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;


const int lg        = 20;
const int mod       = 1e9 + 7;
const ll  inf       = 1e9 + 100;
const int maxn      = 1e6 + 100;
    

#define cl       	clear
#define F        	first
#define S       	second
#define pb       	push_back
#define Sz(x)    	int((x).size())
#define all(x)   	(x).begin(), (x).end()



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int n, m, p, a, b;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        if(x % p) a = i;
    }
    for (int i = 0; i < m; i ++){
        int x;
        cin >> x;
        if(x % p) b = i;
    }
    cout << a + b << '\n';
    return 0;
}

/*test case :

*/