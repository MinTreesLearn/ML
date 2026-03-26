/*
* Author - Sumitp007
* Don't Copy ,Just Watch
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define mod 1000000007
#define maxi INT_MAX
#define mini INT_MIN
#define vi vector<int>
#define vvll vector<vector<long long int>>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vll vector<long long int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define mci map<char,int>
#define pii pair<int,int>
#define readarr(arr,n) for(int i=1;i<=n;i++){cin>>arr[i];}
#define readvi(a,n) for(int i=0;i<n;i++){cin>>a[i];}

void Traverse( vi v ) { 
    for ( auto it : v ) { 
        cout << it << " ";
    }
    cout << endl;
}

bool Asc_Pair_Sort(pii a,pii b) { 
    //* Sorting is done with second element of pairs to be Smaller
    if ( a.second < b.second ) return true;
    return false;
}

ll Fast_Power(ll x,ll y) {
    ll res = 1;
    while ( y != 0 ) {
        if ( y&1 ) res *= x; 
        x*=x;
        y>>=1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    ll a = -1, b = -1 , c = -1 , dupn = n;
    for ( int i = 2 ; i * i <= n ; i++ ) {
        if ( n % i == 0 ) {
            if ( a == -1 ) a = i;
            else if ( b == -1 ) b = i;
            if ( a != -1 && b != -1 ) break;
            n /= i;
        }
    }
    c = ( dupn / ( a * b ) );
    if ( a != b && b != c && a != c && dupn == ( a * b * c ) && a >=2 && b >= 2 && c >=2 ) {
        cout << "YES\n";
        cout << a << " " << b << " " << c << "\n";
    }
    else cout << "NO" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin >> t;
    while ( t -- > 0 ) {
        solve();
    }
    return 0;
}