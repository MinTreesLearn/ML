#include <bits/stdc++.h>
#define ll long long int
#define fr(i, x, n) for (int i = x; i < n; i++)
#define fra(x, v) for (auto x : v)
using namespace std;

ll power(int a, int b)
{
    if (b == 0)
        return 1;
    ll temp = power(a, b / 2);
    if (b % 2 == 0)
        return temp * temp;
    else
        return temp * temp * a;
}
ll fact(ll a){
    ll ans = 1;
    while (a > 0)
    {
        ans *= a;
        a--;
    }
    return ans;
}
ll ones(ll a){
    ll ans = 0;
    while (a > 0)
    {
        ans += a%2;
        a /= 2;
    }
    return ans;
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int dig(ll a)
{
    int ans = 0;
    while (a > 0)
    {
        a /= 10;
        ans++;
    }
    return ans;
}
ll sumdig(ll a)
{
    ll sum = 0;
    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }

    return sum;
}
ll const N = 1000;
ll a[N][N], b[N][N];
// ll ans[10][10];
// void mulM(ll a[10][10] , ll b[10][10] , ll n){
//     fr(i , 0 , n){
//         fr(j , 0 , n){
//            fr(k  , 0 , n){
//                ans[i][j] += a[i][k]*b[k][j];
//            }
            
//         }
//     }
// }
// const double pi = 3.1415926536;
// const int maxo = 2e5 + 5;
// bool check[maxo];
//map<char, ll> mp2;
map<char, ll> mp3;

bool isValid(ll xx, ll yy, ll n, ll m)
{
    return (xx > 0 && xx <= n && yy > 0 && yy <= m);
}

bool sortbyCond(const pair<double, int> &a,
                const pair<double, int> &b)
{
    if (a.second != b.second)
        return (a.second < b.second);
    else
        return (a.first < b.first);
}

// const int N = 1000006;
vector<vector<ll>> v(N);
bool vist[N];
// void dfs(ll x)
// {
//     for(int i =0 ; i< v[x].size() ; i++ ){

//     }
// }
void debug(){
    cout << "test" << endl;
    return ;
}
ll facto[15];
vector<pair<ll,ll>> comb;
void solve(ll ind , ll s , ll x){
    if(ind == 15)return;
    s += facto[ind];
    x++;
    comb.push_back({s , x});
    solve(ind + 1 , 0 , 0);
    solve(ind + 1 , s , x);
    return;
}

map<ll, ll> mpf;
map<ll , ll> mpe;
int main()
{
    ios_base::sync_with_stdio(0);
    ll tt;cin >> tt;
    while(tt--){
    ll n ;cin >> n;
    ll a[n + 5];
    ll mino = 1e9 + 103 , maxo = 0;
    bool g = 0;
    fr(i , 0 , n ){
        cin >> a[i];
        if(a[i] == -1){
           g = 1;
           if(i > 0 && a[i - 1] > -1){
                mino = min(a[i - 1] , mino);
                maxo = max(a[i - 1] , maxo);
            }
        }else {
            if(g){
                mino = min(a[i] , mino);
                maxo = max(a[i] , maxo);
            }
            g = 0;
        }
    }
    
    // cout << mino << " " << maxo << endl;
    ll ans = (maxo + mino)/2;
    ll m = 0;
    fr(i , 0  ,n - 1){
        if(a[i] == -1)a[i] = ans;
        if(a[i + 1] == -1)a[i + 1] = ans;
        m = max(m , abs(a[i] - a[i + 1]));
    }
    cout << m << " " << ans << endl;
    }
    return 0;
}