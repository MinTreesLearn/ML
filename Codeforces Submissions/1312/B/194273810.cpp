/*
           ======Buddha*Dhormo*Songho======
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' >' "".
          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
          \  \ `_.   \_ __\ /__ _/   .-` /  /
      =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='
*/
/*

                 ┌───┬───┬───┬───┐
          =======│ M │ O │ N │ G │=======
                 └───┴───┴───┴───┘

*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define endl "\n"
#define INF 0x3f3f3f3f
#define map  map<int,int>
#define pi pair<int, int>
#define vi vector<int>
#define vii vector <pair<int,int>>
#define viii priority_queue<int,vector<int>,greater<int>>
#define viiii priority_queue<int>
#define vpi vecotr<pi>
#define set set<ll>
#define mp make_pair
#define pb push_back
#define endl '\n'
#define soja(i,a,n)     for(int i=a;i<n;i++)
#define soja1(i,a,n)    for(int i=a;i<=n;i++)
#define ulta(i,n,a)     for(int i=n; i>a; i--)
#define ulta1(i,n,a)    for(int i=n-1; i>=a; i--)
#define IMA INT_MAX
#define IMI INT_MIN
#define PIE 3.1415926536
#define inrange(a, b, c, d)   (a>=0 && a<c && b>=0 && b<d)
#define   all(n) n.begin(),n.end()
#define fi first
#define se second
#define no       cout<<"NO"<<endl;
#define yes      cout<<"YES"<<endl;
#define MAXN 500005
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/******************************************MONG*********************************************************************/
/******************************************MONG*************************01010101010010101010101010101010101010101010/
/******************************************MONG*********************************************************************/
/***************010101001010100101001010***MONG******101010010100101101010010101010101010101010101010010101010101010/
/******************************************MONG*********************************************************************/
/* Mistakes can only make you close to perfect.*/
/******Since Perfection doesn't exist.:) *********************/
void mong_10()
{
    fast;
    ll n;
    cin>>n;
    //vi a(n);
    ll a[n];
    soja(i,0,n)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    soja(i,0,n)
    cout<<a[i]<<" ";
    cout<<endl;
    return;
}

//===============We become what we think about most of the time!All Opinion are my own==================================//
signed main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    cin.exceptions(ios::badbit | ios::failbit);

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout << setprecision(12) << fixed;

    ll test_case;

    test_case=1;

    cin>>test_case;

    while(test_case-->0)

    {

        mong_10();

    }

    return 0;
}
