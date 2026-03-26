
#include <bits/stdc++.h>    
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>       //                      ███████╗████████╗███████╗██╗   ██╗    
#define endl "\n"                               //                 ██╔════╝╚══██╔══╝██╔════╝██║   ██║    
#define F first                                 //                 ███████╗   ██║   █████╗  ██║   ██║    
#define S second                            //                     ╚════██║   ██║   ██╔══╝  ╚██╗ ██╔╝    
#define For(i, x , n) for(ll i=x ;x==0?i<n :i<=n;i++)          // ███████║   ██║   ███████╗ ╚████╔╝     
#define Forn(i , x , n )for(int i = n-x ; x==1?i>=0:i>0;i--)     //╚══════╝   ╚═╝   ╚══════╝  ╚═══╝  
#define cin(v,x,n) For(i,x,n) cin>>v[i]      
#define Insert(v,x,n) For(i,x,n){int in;cin>>in;v.insert(in);}  
#define Cin    long long n ; cin>>n ; long long arr[n] ; cin(arr,0,n) ; 
#define Cin2     LL arr2[n] ; cin(arr2,n) ; 
#define r0 return 0 
#define B begin()
#define E end()
#define RB rbegin()
#define RE rend()
#define pow 1LL*pow
#define Back(s) *s.rbegin()
#define Front(s) *s.begin()
#define PF(x) push_front(x)
#define PB(x) push_back(x)
#define POF pop_front()
#define POB pop_back()
#define Digits(n) (n==0?1:(int)log10(n)+1)
#define Bits(n) (ll)log2(n)+1
#define pof(n) ((n&(n-1))==0)
#define smaller(n) order_of_key(n)  
#define bigger(cont , n , x) ( (n) - cont.smaller( x + 1) )
// #define bigger(cont , x) distance(cont.upper_bound(x) , cont.E)
#define At(n) find_by_order(n) 
#define Idx(cont , x) (int)( L(ms)-(distance(cont.lower_bound(x), cont.E))) // linear time for set... 
#define Sigma(n) (1LL)*( n%2==0?((ll)n/2)*((ll)n+1) :(((ll)n+1)/2)*(ll)n ) // use bracket Sigma(n -+\*)
#define Modx(a,b,c) ((a%c)*(b%c))%c 
#define Modp(a,b,c) ((a%c)+(b%c))%c 
#define Edis(X1 , X2 , Y1 , Y2)  (double) sqrt(   pow( abs( X1 - X2 ) , 2) +  pow(  abs ( Y1 - Y2 )  , 2 )) 
#define intersect(l , r , l2 , r2) (l<=r2 and r >=l2)
#define lcm(a , b) a*b / __gcd(a , b)
#define uniq(x)   sort(All(x)); x.erase(unique(All(x)),x.E)
#define L(s) (int) s.size()    // لا تحاول ان تتخطي قدراتك  //
#define IDX(fnd,s) fnd-s.B    // بل اصنع اليوم بما تستطع  //
#define MAX INT_MAX          //       ستجد في الغد        //
#define MIN INT_MIN         //          ++قدراتك         //
#define uMAX 0xffffffff
#define LA(a) (int)(sizeof(a)/sizeof(a[0]))  
#define full(x) !(x.empty()) 
#define All(v) v.B,v.E    
#define Allr(v) v.rbegin(),v.rend()    
#define getName(x)  #x
#define debug(x) cout<<getName(x)<<" = "<<x<<endl
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define lambda  auto x =[](const Pair &x, const Pair &y) {if (x.second != y.second) {return x.second < y.second;} return x.first < y.first;}
#define lambdaSTEV  [](const Pair &x, const Pair &y) {if (x.F != y.F) {return x.F < y.F;} return x.S < y.S;}
#define Mo_Salah cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avX2,fma")
// #pragma GCC target ("sse4.2")
#define oSet tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define oMap tree<int, int ,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Acc accumulate
// lower_bound and upper_bound work oppositely
#define oMultiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
#define tests int tt  ; cin >> tt  ; while(tt--)
 void judge (){
      #ifndef ONLINE_JUDGE 
      freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);  
      #endif
      }
int rnd(int a, int b){ return a + rand() % (b - a + 1);}
int generator(){int w = rnd(0, 10);return w; }
using namespace std ;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair<ll,ll> Pair ;
const int N = 200005 ;
const ll MOD  = 1e9+7 ;
const double PI =3.141592653589793238462643383279502884;
const int INF = MAX  ; 
const ll  INFl = LLONG_MAX ; 
int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1,-1, 1 };
char dc [] = {'D','U','R','L'} ; 
int knightX[]  = { 2, 1, -1, -2, -2, -1, 1, 2 };
int knightY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
ll n  , m , components  , k ;   
// bool f ; 
bool Salka(int x, int y) { return x > 0 && y > 0 && x <= n && y <= m; } // 1 based
/*equal_less 
 auto it = ms.upper_bound(k-i+1) ; 
if((it!=ms.E and it!=ms.B)or (it==ms.E and full(ms)))
it-- ;
*/
template <typename T1 , typename T2>void dabt_el_masna3(T1 &v , T2 &v2){ v =T1(n+1) ; v2 =T2(n+1) ; }
struct point{public : double x , y ;} ; 
struct triple{public : ll a , b , c ;} ; 
template <typename T>void debugcont(T&v){for(auto i : v)debug(i);}
template <typename T>void debugcont2(T&v){for(auto [l ,r] : v)debug(l) ,debug(r) ; }
template<typename T> auto equal_less(T&v  , int value){ //return iterator needed or end when fail
auto it = upper_bound(All(v) , value) ; 
if((it!=v.E and it!=v.B) or (it==v.E and full(v)))
it-- ;
else it=v.E;
return it; }
                                /*     “You just keep pushing. You just keep pushing.  
                                           I made every mistake that could be made.   
                                                But I just kept pushing.”           
                                                     — René Descartes              */

                        /*                         Steven's Golden Rules ❤
                                            ❏ if you feel so dumb you didnt work enough
                                        ❏ give it more time more effort you will be better 
                                        ❏ if it gives WA that means you will learn something 
        ❏ every problem either teach you something or make you better in something other than that you didnt realy solve it .  */
                                                //*
                                               
                                                    main(){
                                                    judge() ; 
                                                    Mo_Salah ;
                                                    tests{
                                                        int n ; cin>> n ;
                                                        vector<vector<int>> v(1001);
                                                        string s ="" ; 
                                                        For(i,0,n){
                                                            int x , y ; cin  >> x >> y ; 
                                                            v[x].push_back(y);
                                                        }
                                                        int x = 0 , y = 0 , ans  = 0 ;
                                                        while(x<=1000){
                                                            if( full(v[x]) ){
                                                                sort(v[x].B , v[x].E) ; 
                                                                for(auto i : v[x]) {
                                                                    if(i>=y) s.append(i-y,'U') , y= i , ans++;
                                                                    else break ; 
                                                                }
                                                            }
                                                              if( ans == n )break;
                                                                x++ ;
                                                                s.push_back('R') ;  
                                                        }
                                                        if( ans == n ) cout<<"YES"<<endl<<s<<endl;
                                                        else cout<<"NO"<<endl;


                                                    }
                                                    
                                                    }
                                                        
     
                                                    