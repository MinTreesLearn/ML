/*
 *  Show me your beautiful smile :)
 *
 *  author:  Ahmed khaled ( _GOM3A_ )
 *
 * */
#include <bits/stdc++.h>
using namespace std;
#define fast_IO(x)              ios_base::sync_with_stdio(false);cin.sync_with_stdio(0); cout.sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define fraction                cout<< fixed <<showpoint <<setprecision
#define what_is(x)              cerr << #x << " is " << x << '\n';
#define PI                      3.141592653589793238462643383279
#define Write(x)                freopen (x,"w",stdout)
#define Read(x)                 freopen (x,"r",stdin)
#define all(x)                  x.begin(),x.end()
#define Reverse(x)              reverse(all(x))
#define Sort(x)                 sort(all(x))
#define Yes                     cout<<"YES"
#define yes                     cout<<"yes"
#define No                      cout<<"NO"
#define no                      cout<<"no"
#define pi                      acos(-1);
#define ln                      '\n'
typedef deque<long long>        dll;
typedef vector<long long>       vll;
typedef set<long long>          sll;
typedef long long               ll;
typedef pair<ll,ll>             pl;

//**prototype**//
inline void _GOM3A_(void);
template<typename T, typename ...Opts>
bool any_of(T val, Opts ...opts);
ll getRandomNumber(ll low = 0, ll high = 100);
bool isPrime(ll n);
deque<ll> factorization(ll n);
bool isPalindrome(string s);
ll binaryToDecimal(string s);
//**prototype**//

int main() {
    _GOM3A_();
    //********** code ***************
    ll size;
    cin >> size;
    vll numbers(size);
    ll cnt = 0;
    for_each(numbers.begin() , numbers.end() , [](ll &x){cin >> x ; });
    for (int i = 0; i < size; ++i) {
            if( ! numbers[i]  )
                break;
            numbers.push_back(1);
    }
    ll i = 0 , j = 0;
    ll mx = 0;
    while( i < numbers.size() && j < numbers.size() )
    {
        if( !numbers[j] )
        {
            mx = max( mx , (j-1) - i + 1);
            j++;
            i = j;
        }
        else
        {

            mx = max( mx , j - i + 1 );
            j++;
        }
    }
    cout<<mx;
    //********** code ***************
}

//****************************************    helping function    ****************************************
inline void _GOM3A_(void){
    fraction(6);
    fast_IO(  author: _GOM3A_ );
}
template<typename T,typename ...Opts>
bool any_of(T val, Opts ...opts)
{
    return ( ... || (val == opts) );
}
ll getRandomNumber(ll low , ll high ){
    static ll  fo = 0;
    if( fo == 92233720368547758 )
        fo = 0;
    srand((unsigned) time(NULL) + fo );
    fo++;
    return ( ( rand() % (high - low + 1)) + low );
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
deque<ll> factorization(ll n){
    set<ll> result;
    ll i ;
    for(i = 1; i * i  < n ; i++){
        if( !( n%i ) )
        {
            result.insert(i);
            result.insert(n/i);
        }
    }
    if(i*i==n)
        result.insert(i);
    dll m   ( all(result) );
    return m;
}
bool isPalindrome(string s)
{
    ll size = s.size();
    ll halfSize = s.size() / 2;
    for (int i = 0; i < halfSize; i++) {
        if (s[i] != s[size - i - 1]) {
            return false;
        }
    }
    return true;
}
ll binaryToDecimal(string s)
{
    bitset<64> bits(s);
    ll number = bits.to_ulong();
    return number;
    //return stol(s,nullptr,2);
}