/*
(اللهم صلْ وسلم وزد وبارك على سيدنا محمد )

꧁IslaM_SobhY꧂

 */
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int>> vp;
#define all(v) v.begin(),v.end()
#define sz(x) x.size()
#define SUPERPOWER ios_base::sync_with_stdio(false); cout.tie(0);
#define cin(v) for(auto &i:v)cin>>i
#define cout(v) for(auto &i:v)cout<<i<< " "
#define ll long long
#define  el "\12"
#define format(n) fixed<<setprecision(n)
#define YES cout << "YES" << el;
bool AdelCan(vi v,int n,ll Yasser)
{
    int l = 0;
    int r = 0;
    ll sum = 0;
    while(l < n)
    {
        while(r < n && sum  < Yasser)
        {
            sum+=v[r];
            r++;
        }
        if(sum >= Yasser && (r - l) < n)
        {
            return 1;
        }
        sum-=v[l];
        l++;
    }
     if(sum >= Yasser && (r - l + 1) < n)
     {
         return 1;
     }
     return 0;


}
int main() {
     // For getting input from input.txt file
    //freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    //freopen("output.txt", "w", stdout);
     SUPERPOWER;
int t = 1;cin >> t;
while(t--)
{
    //write the code here
    int n;cin >> n;
    vi v(n);
    ll Yasser = 0;
    for(int i = 0; i <n; i++)
    {
        cin >> v[i];
        Yasser+=v[i];
    }
    bool Adel = AdelCan(v,n,Yasser);
    if(Adel)
    {
        cout << "NO" <<el;
    }else
    {
        cout << "YES" <<el;
    }




}
  return 0;
}





