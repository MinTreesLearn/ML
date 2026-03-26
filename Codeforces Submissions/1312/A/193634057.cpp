#include<bits/stdc++.h>
using namespace std;

#define     w(t)                    int t;cin >> t; while(t--)
#define     ll                      long long
#define     get_arr(x,o,n)          for(int i=o;i<n;i++){cin >> x[i];}
#define     fr(i,x,y)               for(int i=x;i<y;i++)
#define     fr_rev(i,x,y)           for(int i=x;i>y;i--)
#define     sz(x)                   x.size()
#define     sp                      " "
#define     vsort(v)                sort(v.begin(),v.end())
#define     vsort_rev(v)            sort(v.begin(),v.end(), greater<int>())
#define     pb                      push_back
#define     vi                      vector<int>
#define     br                      cout << endl;
#define     prints(v)               for(auto u:v)cout << u << sp;
#define     print(v)                for(auto u:v)cout << u ;


#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL));


bool compare(int a ,int b)
{
    return a > b ? true : false;   
}

void solve(){
}
int main(int argc, char const *argv[])
{
    fastread()
    w(t)
    {
        int a,b;
        cin >> a>> b;
        if(a%b==0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
   
}