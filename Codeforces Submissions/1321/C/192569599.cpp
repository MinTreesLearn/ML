// @author manish926
//NEVER GIVE UP,struggle... ,struggle...,struggle....        success.
#include<bits/stdc++.h>
using namespace std;
#define ll                            long long int
#define ld                            long double
#define f1(i,n)                       for(int i=0;i<n;i++)
#define f3(j,n)                       for(int j=0;j<n;j++)
#define f2(i,n,x)                     for(int i=x;i<n;i++)
#define vi                            vector<long long>
#define pi                            pair<long long,long long>
#define vvi                           vector<vector<int,int>> 
#define vll                           vector<ll>
#define mi                            map<long long,long long>
#define umi                           unordered_map<long long,long long>
#define si                            set<long long>
#define usi                           unordered_set<long long>
#define pb                            push_back
#define pp                            pop_back
#define sortv(v)                      sort(v.begin(),v.end())
#define e                             '\n'
#define all(x)                        x.begin(),x.end()
#define mp                            make_pair

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL); 

int n;cin>>n;
string s;cin>>s;
int ans =0;
for(char ch = 'z' ; ch>='b';){
   int t = 0;
   for(int i=0;i<s.size();i++){
        if(s[i] == ch){
             if(i > 0 && ((ch-'0')-1 == (s[i-1]-'0'))){
               s.erase(s.begin()+i);
               ans++;
               t++;
               break;
             }else if(i<n-1 && ((ch-'0')-1 == (s[i+1]-'0'))){
               s.erase(s.begin()+i);
               ans++;
               t++;
               break;
             }
        }
   }
   if(t==0)ch--;
   
}
cout<<ans<<e;

return 0;
}
