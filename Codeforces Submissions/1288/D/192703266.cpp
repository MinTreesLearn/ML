


/*

1-> One day I will be 6* at Codechef and CandidateMaster at CodeForces

2-> Journey is not going to be so easy, sometimes shitty thoughts will rain on me
    but that should not be the end, prevent self giving up at that moment.
    CP is not a fight, it is Love.

3-> Dont panic about rating, rating takes time to come to your level
    Dont forget rating is direcly propotional to skills, skills are not directly
    propotional to rating.

4-> Keep on practising the questions above your level.

5-> Keep helping people, fellow programmers, junior, create a healthy coding environment.
    Keep learning everyday.

6-> Be Honest to Yourself.

*/
#include<bits/stdc++.h>
using namespace std;
#define fori(a,b,c) for(int i = a; i<b ; i+=c )
#define forj(a,b,c) for(int j = a; j<b ; j+=c )
#define forf(a,b,c) for(int f = a; f<b ; f+=c )
#define tt int f; cin>>f;while(f--)

#define mp make_pair
#define pb push_back
#define um unordered_map
#define si set<int> 

#define ull unsigned long long int
#define ll long long int 
#define pii pair<int,int>
#define pci pair<char,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>

#define mod 1000000007
#define inf 2147483647
#define ninf -2147483648
#define llmax 9223372036854775807

#define vi vector<int> 
#define vll vector<ll>
#define vb vector<bool>

#define vp vector<pair<int,int> > 
#define vpci vector<pair<char,int> >
#define vpll vector<pair<ll,ll>>
#define vv vector<vector<int>>
#define vc vector<char> 
#define vs vector<string> 

#define fr first
#define sc second

#define st SegmentTree
#define endl '\n' 
#define dd debug 

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int , null_type , less<int>  , rb_tree_tag , tree_order_statistics_node_update>
using namespace __gnu_pbds;

// there are two functionf of this 
// s.find_by_order(int x);  - > finds out the number of elements strictly lesser than x in ordered set s
// s.order_of_key(int i)  -> this return iterator to the value at index i in O log(n) time

// Premetive Data Types 
void _print(int x ){ cerr<<x;} void _print(ll x ){ cerr<<x;}void  _print(ull x ){ cerr<<x;}
 void _print(char x ){ cerr<<x;}void  _print(float x ){ cerr<<x;} void _print(bool x ){ cerr<<x;}
void _print(string x ){ cerr<<x;} 


// SET && MULTISET

template<class G> void _print(multiset<G> &s){for(auto val : s )cout<<val<<endl;}
template<class G> void _print(set<G> & s){for(auto val : s )cout<<val<<endl;}

template<class T , class G>
void _print(set<pair<T,G>> & arr)
{for(auto ch:arr)   cerr<<"("<<ch.first<<" ,"<<ch.second<<")  "; cerr<<endl;}


// Unordered Map

template<class G , class T>
void _print (um<G,T> & x)    { cerr<<endl;   for(auto a:x){  cerr<<"("<<a.first<<","<<a.second<<")";    }   cerr<<endl;     }


// Map
template<class G , class T>
void _print (map<G,T> & x)    { cerr<<endl;   for(auto a:x){  cerr<<"("<<a.first<<","<<a.second<<")";    }   cerr<<endl;     }


// Vector
template<class T>
void _print(vector<T> & arr )
{
    for(auto ch:arr)cerr<<ch<<" ";
    cerr<<endl;
}
template<class G , class T>
void _print(vector<pair<G,T> > & arr){fori(0 , arr.size() , 1){cerr<<"("<<arr[i].first<<","<<arr[i].second<<") ";}cerr<<endl;}

template<class T>
void _print(vector< vector<T> > & graph)
{
    cerr<<endl;
    fori(1 , graph.size() , 1)
    {
        cerr<<i<<" ->";
        forj(0 , graph[i].size() , 1)
        {
            cerr<<graph[i][j]<<" ";
        }
        cerr<<endl;
    }
}

template<class A , class B , class C>
void _print(vector<pair<A,pair<B,C > > > & arr)
{
    fori(0 , arr.size() , 1)
    {
        cerr <<"(" << arr[i].first << "," << arr[i].second.first << "," << arr[i].second.second <<") ";
    }
    cerr<<endl;
}

// Premetive Data Types 
template<class T>void _print(T & x )
{
    cerr<<x<<endl;
}



// Vector Sort
template<class T>void sort(vector<T>&arr){sort(arr.begin(), arr.end());}
template<class T>void sort1(vector<T>&arr){sort(arr.begin()+1, arr.end());}


// Vector and String Reverse
template<class F>
void reverse(vector<F> & arr )
{reverse(arr.begin() , arr.end());}

template<class F>
void reverse1(vector<F> & arr )
{reverse(arr.begin()+1 , arr.end());}

void reverse(string & arr)
{reverse(arr.begin() , arr.end());}

void reverse1(string & arr)
{reverse(arr.begin()+1 , arr.end());}



// Pair
template<class T1 , class T2>
void _print(pair<T1,T2> & a)
{
    cerr<<a.first<<" "<<a.second<<endl;
}



// READING & PRINTING

// Premitive data types
template<class T>
void r(T & a )
{cin>>a;}

template<class T>
void r(T & a , T & b )
{cin>>a>>b;}

template<class T>
void r(T & a , T & b , T &c )
{cin>>a>>b>>c;}

template<class T>
void r(T & a , T & b , T &c , T &d )
{cin>>a>>b>>c>>d;}

template<class T>
void r(T & a , T & b , T &c , T &d , T &e)
{cin>>a>>b>>c>>d>>e;}

void r(char & ch){cin>>ch;}
void r(bool & a){cin>>a;}

void r(string & s) {cin>>s;}
template<class T>




// Reading Vectors
void r(vector<T> & arr)
{fori(1 , arr.size() ,1 )cin>>arr[i];}

template<class T>
void read(vector<T> & arr)
{fori(0 , arr.size() ,1 )cin>>arr[i];}

template<class T1 , class T2>
void r(vector<pair<T1,T2>> & arr)
{fori(1 , arr.size() , 1)cin>>arr[i].first>>arr[i].second;}

template<class T1 , class T2>
void read(vector<pair<T1,T2>> & arr)
{fori(0 , arr.size() , 1)cin>>arr[i].first>>arr[i].second;}




// MATRIX
template<class T1 , class T2>
void r(vector<vector<T1>> & graph )
{
    fori(1 , graph.size() , 1) 
        r(graph[i]);
}

// MATRIX for ZERO
template<class T1 , class T2>
void read(vector<vector<T1>> & graph )
{
    fori(0 , graph.size() , 1) 
        read(graph[i]);
}

// TREE
void r(vector<vi> & graph )
{
    fori(1 , graph.size() , 1)
    {
        int a , b;r(a , b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
}


// GRAPH
void r(vector<vi> & graph , int m )
{
    fori(1 , m+1 , 1)
    {
        int a , b;r(a , b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
}




// Printing Vectors
template<class T>
void p(vector<T> & arr)
{fori(1 , arr.size(), 1)cout<<arr[i]<<" ";cout<<endl;}

template<class T>
void print(vector<T> & arr)
{fori(0 , arr.size(), 1)cout<<arr[i]<<" ";cout<<endl;}

template<class T1 , class T2>
void p(vector<pair<T1,T2>> & arr)
{fori(1 , arr.size() , 1)cout<<"("<<arr[i].first<<","<<arr[i].second<<")  ";cout<<endl;}

template<class T1 , class T2>
void print(vector<pair<T1,T2>> & arr)
{fori(0 , arr.size() , 1)cout<<"("<<arr[i].first<<","<<arr[i].second<<")  ";cout<<endl;}







#ifndef ONLINE_JUDGE
#define debug(x)cerr<< #x<<' ';_print(x); cerr<<endl;
#else 
#define debug(x)
#endif

/* ------------------------------------------------------------------------*/


int g = 97 , f = 98;

void convertFilledToMadeBy(vi & filled , vi & madeBy, vi & powers, int name){
    int n = filled.size();

    fori(0 , powers[n] , 1)
    {
        bitset<8> temp(i);
        int made = 0;
        forj(0 , 8 , 1)
        {
            if(temp[j])
            {
                made += powers[filled[j]];
            }
        }
        madeBy[made] = name;
    }
}




bool possibleToMakeThis(vv & arr , int n  , int m , int val )
{
    vi madeBy(257 , -1);
    vi powers(8);

    powers[0] = 1;
    fori(1 , 8 , 1)powers[i] = powers[i-1] * 2;

    fori(1 , n+1 , 1)
    {
        vi filled;  
        int neededValue = 0;

        // dd(arr[i])
        int mn = arr[i][1];

        forj(1 , m+1 , 1){
            if(arr[i][j]>=val){
                filled.pb(j-1);
            }
            else 
                neededValue += powers[j-1];
            mn = min(mn , arr[i][j]);
        }

        if(mn >= val){
            g = i;
            f = i;
            return true;            
        }

        convertFilledToMadeBy(filled, madeBy, powers , i);

        if(madeBy[neededValue] != -1){
            g = i;
            f = madeBy[neededValue];
            return true;
        }


        // dd(filled)
        // dd(madeBy)

    }

    return false;
}









int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("debug.txt", "w" , stderr);
freopen("input.txt", "r" , stdin);
freopen("output.txt", "w" , stdout);
#endif
cout << setprecision(12) << fixed;
cerr << setprecision(12) << fixed;

    
int n , m;cin>>n>>m;

vv arr(n+1 , vi(m+1));
set<int>s;
map<int,int>numbering;

fori(1 , n+1 , 1){
    forj(1 , m+1 , 1){
        cin>>arr[i][j];
        s.insert(arr[i][j]);
    }
}

vi answers;
answers.pb(0);

for(auto ch:s){
    answers.pb(ch);
}

int low = 1 , high = s.size() , ans = low;


while(low<=high){
    int mid = (low+high)/2;
    // dd(mid)
    // if possible to make this the maximum
    // dd(answers[mid])
    if(possibleToMakeThis(arr , n , m , answers[mid]))
    {
        // cerr<<"here we are"<<endl;
        low = mid+1;
        ans = mid;
    }
    else {
        // cerr<<"there we are"<<endl;
        high = mid-1;
    }
    // cerr<<endl;
}

cout << g  << ' ' << f << endl;


    return 0; 
}

