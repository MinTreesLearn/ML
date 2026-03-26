#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <string>
#include <queue>
#include <cstring>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef map<int, int> mii;

#define endl "\n"
#define ENDL "\n"
#define endla(n) " \n"[i == n - 1]
#define ENDLA(n) " \n"[i == n - 1]
#define Ber0Silk int main (void)
#define cin(v) for(auto& i : v) cin >> i;
#define cout(v) for(auto& i : v) cout << i << " "; cout << ENDL;
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define rv(x) return void(cout << x << endl)
#define all(v) v.begin(),v.end()
#define next continue;
#define NEXT continue;
#define F first
#define S second
#define on(n) [i == n - 1]

const int INF = int(1e9) + 7;
const long long N = 1e6 + 10;
const double PI = acos(-1);
const int MOD = 1e9 + 7;

template<typename T> bool CompareVe(vector<T> v1, vector<T> v2) { bool f = v1.size() == v2.size(); if (!f) return false; for (int i = 0; i < v1.size(); i++) if (v1[i] != v2[i]) return false; return true; }
template<typename T> bool sorted(vector<T> v) { for (int i = 0; i < v.size() - 1; i++) if (v[i] > v[i + 1]) return false; return true; }

/*

prime factorization
*/

// const int lim = 1000001;
// set<ll> v;
// void calc(){


//     static bool arr[lim];

//     for(int i = 2;i*i < lim;i++){
//         if(!arr[i]){
//             for(int j = i*i;j < lim;j+=i){
//                 arr[j] = true;
//             }
//         }
//     }


//     for(ll i = 2;i < lim;i++){
//         if(!arr[i]){
//             v.insert(((ll)i*i));
//         }
//     }

// }


// Solution here
void solve() {
    string s; cin >> s;
    vector<ll> v;
    //ll n = s.length();
    ll c = 0;
    for(int i = 0;i < s.length();i++){
        if(s[i] == '1'){
            v.push_back(i);
        }
    }
    if(v.size() != 0)
    for(int i = 0;i < v.size() - 1;i++){
        if((v[i + 1] - v[i]) > 1) c += v[i + 1] - v[i] - 1;
    }
    
    rv(c);
}

Ber0Silk{
    FAST
    //calc();
    ll t = 1; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
 CODING. . .
*/