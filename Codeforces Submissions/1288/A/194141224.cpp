//NEWBIE CONTESTANT
// copy right ©  12/2/2022 to ESLAM SAYED (ESLAM 7215) Educational DIV2--> 143
#include <bits/stdc++.h>
using namespace std ;
#define clo cout << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#define NB iostream::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define OUT  cout << setprecision(6) << fixed ;
#define ul unsigned long long
#define yes cout << "YES\n" ;
#define PI 3.14159265358979323846264338327
#define no cout << "NO\n" ;
#define all(ans) ans.begin() , ans.end()
#define allr(ans) ans.rbegin() , ans.rend()
#define N <<"\n" ;
#define S(c) string (1 , c)
const int MAX = 1e8 ;
typedef long long ll ;
typedef double long dll ;
using namespace std ;
const ll MOD = 1073741824 ;
template <typename t>
istream & operator >> (istream & in, vector<t> & es){
    for (auto & i : es){
        in >> i ;
    }
    return in ;
}
template<typename t>
istream & operator >> (vector<t> & es , int n){
    t rr ;
    for (int i = 0 ; i < n ; i++){
        cin >> rr ;
        es.push_back(rr) ;
    }
}
ll gcd(ll a , ll b){
    if (b == 0)
        return a ;
    return gcd(b , a % b ) ;
}
int lcm (long long a , long long b){
    return a / gcd(a , b) * b ;
}
bool pal (string w ){
    string ss = w;
    reverse(ss.begin() , ss.end()) ;
    if (w == ss)
        return true;
    else
        return false;
}
bool isprime (ll a){
    if (a == 1 || a == 0)
        return false ;
    if (a == 2)
        return true ;
    for (int i = 2 ; i <= sqrt(a) ; i++){
        if (a % i == 0)
            return false ;
    }
    return true ;
}
template <typename t>
ostream & operator << (ostream & out , vector<t> es){
    for (auto i : es){
        out << i << " ";
    }
    out N
    return out ;
}
ll fact (ll num){
    ll sum = 1 ;
    for (ll i = 2 ; i <= num ; i++){
        sum *= i ;
    }
    return sum ;
}
bool check (map<char , ll>mp , ll k){
    bool r = true ;
    ll ch = 0;
    ll e = 0 ;
    for (auto i : mp){
        e ++ ;
        if (r) {
            ch = i.second;
            r = false ;
        }else if (i.second != ch){
            return false ;
        }
    }
    if (e == k) {
        return true;
    }else {
        return false ;
    }
}
bool is (int n){
    string r = to_string(n) ;
    int e = r.size() ;
    for (int i = 0 ; i < e ; i++){
        if (r[i] != '7' && r[i] != '4'){
            return false ;
        }
    }
    return true;
}
string binary (int n , int k){
    string w ;
    while (n > 0){
        if (n % 2 == 0){
            w += '0' ;
        }else {
            w += '1' ;
        }
        n /= 2 ;
    }
    while (w.size() < k){
        w += '0' ;
    }
    reverse(all(w)) ;
    return w ;
}

/*to isolate the primes from 1 to n*/
//for (ll i = 2 ; i * i <  1000001 ; i++){
//    if (!es[i]){
//  for (ll j = i + i ; j < 1000001 ; j += i)
//      es[j] = true ;
//  }
//}
//for (int i = 2 ; i < es.size() ; i++){
//  if (!es[i]){
//      cout << i << " " ;
//  }
//}

vector<string>ww ;
void sol (string w , int i ){
    if (i == 1){
        string qq , q;
        for (int j = 0 ; j < w.length() ; j++){
            if (w[j] == 'A'){
                qq += '(' ;
                q += ')' ;
            }else {
                qq += w[j] ;
                q += w[j];
            }
        }
        sol(qq , i + 1) ;
        sol (q , i + 1) ;
    }
    else if (i == 2){
        string qq , q;
        for (int j = 0 ; j < w.length() ; j++){
            if (w[j] == 'B'){
                qq += '(' ;
                q += ')' ;
            }else {
                qq += w[j] ;
                q += w[j];
            }
        }
        sol(qq , i + 1) ;
        sol (q , i + 1) ;
    }
    else if (i == 3){
        string qq , q;
        for (int j = 0 ; j < w.length() ; j++){
            if (w[j] == 'C'){
                qq += '(' ;
                q += ')' ;
            }else {
                qq += w[j] ;
                q += w[j];
            }
        }
        if (qq[0] != qq[qq.length() - 1 ]) {
            ww.push_back(qq);
        }
        if (q[0] != q[q.length() - 1] ) {
            ww.push_back(q);
        }
        sol(qq , i + 1) ;
        sol (q , i + 1) ;
    }else
        return;
}
vector<ll> taken (10000) ;
ll fib (ll n  , int a){
    if (a  == n + 1 ){
        return taken[n ] ;
    }
    if (a == 0) {
        taken[a] = 0;
        return fib(n, a + 1);
    }
    else if (a == 1) {
        taken[a] = 1;
        return fib(n, a + 1);
    }else {
        taken[a] = taken[a - 1] + taken[a - 2] ;
        return fib(n , a + 1) ;
    }
}



//vector<int>os {1 , 2 , 3};
//vector<int>ans ;
//int y = 0 ;
//void sol (string w){
//    if (w.length() == 5){
//        cout << w N
//        y ++ ;
//        return;
//    }
//    sol(w + "R") ;
//    sol(w + "G") ;
//    sol(w + "Y") ;
//    sol(w + "E") ;
//}
ll div (ll n){
    double tt = sqrt(n) ;
    set<ll>st ;
    for (int i = 1 ; i <= tt ; i++){
        if (n % i == 0){
            st.insert(i) ;
            st.insert(n / i) ;
        }
    }
    return st.size() ;
}
//bool fun (ll n , vector<ll>es , vector<ll>os ){
//    ll st = 1e9 , sr = 0 ;
//    for (auto i : os){
//        ll tt = i + n , ttt = i - n ;
//        ll l = -1 , r = es.size() ;
//        ll fs , sn;
//        while (l < r - 1){
//            ll mm = (l + r ) / 2 ;
//            if (es[mm] <= tt){
//                l = mm ;
//            }else {
//                r = mm ;
//            }
//        }
//        fs = l ;
//        l = -1 ; r = es.size() ;
//        while (l < r - 1){
//            ll mm = (l + r ) / 2 ;
//            if (es[mm] < ttt){
//                l = mm ;
//            }else {
//                r = mm ;
//            }
//        }
//        sn = r ;
//        if (min(sn , fs) > sr){
//            if (abs(min(fs , sn) - sr) == 1){
//            }else {
//                return false ;
//            }
//        }
//        st = min(st , sn) ;
//        sr = max(sr , fs) ;
//    }
//    if (st == 0 && sr >= es.size() - 1)
//        return true ;
//    else
//        return false ;
//}
//void sol (){
//    ll n , m ;
//    cin >> n >> m ;
//    unordered_map<ll , ll> aa , rr;
//    vector<ll>es , os;
//    for (int i = 0 ; i < n ; i++){
//        ll y ;
//        cin >> y;
//        if (aa[y] == 0){
//            es.push_back(y) ;
//            aa[y] = 1 ;
//        }
//    }
//    ll minss = 4e9 ;
//    for (int i = 0 ; i < m ; i++){
//        ll y ;
//        cin >> y;
//        if (rr[y] == 0){
//            os.push_back(y) ;
//            rr[y] = 1 ;
//            if (n == 1){
//                minss = min(minss , abs(y - es[0])) ;
//            }
//        }
//    }
//    if (n == 1) {
//        cout << minss ;
//        return  ;
//    }
//    ll l = -1e9 , r = 4e9 + 10 ;
//    while (l < r - 1){
//        ll mm = (l + r) / 2 ;
//        if (fun(mm , es , os)){
//            r = mm ;
//        }else {
//            l = mm ;
//        }
//    }
//    cout << abs(r) ;
//}
int main () {
    NB
    OUT
    int t = 1 ;
    cin >> t ;
    while (t--){
        ll n , d ;
        cin >> n >> d ;
        bool fl = true ;
        if (n >= d)
            yes
        else {
            for (ll i = 1; i < 100000; i++) {
                ll aaa = i + d / (i + 1);
                if (d % (i + 1) != 0) {
                    aaa++;
                }
//            cout << aaa N
                if (aaa <= n) {
//                cout << i N
                    fl = false;
                    yes
                    break;
                }
            }
            if (fl)
                no
        }
//        if (y <= n || rr <= n || rrr <= n || r <= n || a <= n){
//            yes
//        }else if (n >= d){
//            yes
//        }else
//            no
    }
}
