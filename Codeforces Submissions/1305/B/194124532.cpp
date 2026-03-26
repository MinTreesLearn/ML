/** 
 * Surly
 * 18.2.2023
**/

#include<bits/stdc++.h>
 
#define pb push_back
#define nw cout<<"\n";
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define mpr make_pair
#define memset(v,x) memset(v,x,sizeof(v))
#define len(v) int(v.size())
#define put(v,x) v.insert(begin(v),x)
#define wis(x) std::cerr <<"Line"<<__LINE__<<": "<<#x<<" is "<<x<<std::endl

using namespace std;
  
typedef int_fast64_t ll; 
typedef vector<int> vi;
typedef vector<ll> vll;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] --> [", _debug(__VA_ARGS__);
#endif

template<typename type>istream& operator>>(istream& istream , deque<type> &v) {
if(v.size()) { for(auto &i : v) { istream>> i; } return istream; }
istream>>ws;  string str; getline(istream , str); stringstream  stream(str);
move(istream_iterator<type>(stream),istream_iterator<type>(),back_inserter(v));
return istream;}template<typename type>ostream& operator<<(ostream& ostream , vector<type> &
v){move(all(v),ostream_iterator<type>(ostream," ")); nw; return ostream;}
 

  int main ( void )
{                 
                         time_t Time;
                          time(&Time);
                   cerr<<ctime(&Time);
             ios_base::sync_with_stdio(false);
               cin.tie(NULL),cout.tie(NULL);
               cout<<fixed<<setprecision(2);
    auto starttime=chrono::steady_clock::now();
    
    string str; cin>> str;
    deque<int> left , right;
    int first = 0 , last = len(str)-1;
    
    while(first<last) {
     while(first<len(str) and str.at(first)==')')
      first++;
     while(last>0 and str.at(last)=='(')
      last--;
     if(first<len(str) and last>=0 and first<last) {
       left.pb(first+1);
       right.push_front(last+1);
       first++;
       last--;
     }
    }
    
    if(!len(left) and !len(right)) {
      cout<<0; nw;
    }
    else {
     cout<< 1 <<'\n' << 2*len(left); nw;
     for(auto &i : left)
      cout<<i <<" ";
     for(auto &i : right) 
      cout<< i <<" ";
    }
    

    auto endtime=chrono::steady_clock::now(); 
    cerr<<endl<<"Elapsed Time: "
         <<chrono::duration_cast<chrono::milliseconds> (endtime-starttime).count()
          <<" milliseconds"<<endl;
    return 0;
 }

