#include<iostream>
using namespace std;
#include <cmath>
#include <algorithm>
#define ll long long
#define fi first
#define se second
#define sst string
#define pb push_back
#ifndef _GLIBCXX_NO_ASSERT
 #include <cassert>
 #endif
 #include <cctype>
 #include <cerrno>
 #include <cfloat>
 #include <ciso646>
 #include <climits>
 #include <clocale>
 #include <cmath>
 #include <csetjmp>
 #include <csignal>
 #include <cstdarg>
 #include <cstddef>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <ctime>
 #if __cplusplus >= 201103L
 #include <ccomplex>
 #include <cfenv>
 #include <cinttypes>
 #include <cstdbool>
 #include <cstdint>
 #include <ctgmath>
 #include <cwchar>
 #include <cwctype>
 #endif
 #include <algorithm>
 #include <bitset>
 #include <complex>
 #include <deque>
 #include <exception>
 #include <fstream>
 #include <functional>
 #include <iomanip>
 #include <ios>
 #include <iosfwd>
 #include <iostream>
 #include <istream>
 #include <iterator>
 #include <limits>
 #include <list>
 #include <locale>
 #include <map>
 #include <memory>
 #include <new>
 #include <numeric>
 #include <ostream>
 #include <queue>
 #include <set>
 #include <sstream>
 #include <stack>
 #include <stdexcept>
 #include <streambuf>
 #include <string>
 #include <typeinfo>
 #include <utility>
 #include <valarray>
 #include <vector>
 
 #if __cplusplus >= 201103L
 #include <array>
 #include <atomic>
 #include <chrono>
 #include <condition_variable>
 #include <forward_list>
 #include <future>
 #include <initializer_list>
 #include <mutex>
 #include <random>
 #include <ratio>
 #include <regex>
 #include <scoped_allocator>
 #include <system_error>
 #include <thread>
 #include <tuple>
 #include <typeindex>
 #include <type_traits>
 #include <unordered_map>
 #include <unordered_set>
 #endif
#define maxco 100000+5
#define lld long double
#define cha ios_base::sync_with_stdio(false);
#define mod 1000000007
#define ffl cout.flush();
#define phi acos(-1)
//
//ll a[200069];
//sst t="";
//void precom(){
//    for(ll i=0;i<1000;i++){
//        t+=(phi%10);
//        phi/
//    }
//}


//int main(){
//    ll tc;
//
//    cin>>tc;
//    while(tc--){
//        vector <ll> vec;
//        ll n,s,r;
//        cin>>n>>s>>r;
//        ll sisa=s-r;
//        vec.pb(sisa);
//        cout<<sisa<<" ";
//        n--;
//        if(r%n==0){
//            ll t=n;
//            while(t--){
//                cout<<r/n<<" ";
//            }
//        }
//        else{
//
//        }
//        cout<<endl;
//    }
//}
ll a[200069];
ll le[1569][1509];
ll dp[300069];

int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    memset(le, 0, sizeof(le));
    for(ll i=1;i<=n;i++){
        le[i][a[i]]=i;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=1500;j++){
            if(le[i][j]==0){
                le[i][j]=le[le[i][j-1]-1][j-1];
            }
        }
    }
    memset(dp, mod, sizeof(dp));
    dp[0]=0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=1500;j++){
                if(le[i][j]!=0){
                    dp[i] = min(dp[i], dp[le[i][j]-1]+1);
                }
            }
        }
    cout<<dp[n];
}

