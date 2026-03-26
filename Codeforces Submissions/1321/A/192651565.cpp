#include <bits/stdc++.h>

using namespace std;
//-------------------------------------------------------
void fast(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}
//-------------------------------------------------------
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(s) (int)(s.size())
#define inf 0x3f3f3f3f3f3f3f3fLL
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define clr(arr, val) memset(arr, val, sizeof(arr))
string ABC = "abcdefghijklmnopqrstuvwxyz";
//const int dr[] {-1, -1, 0, 1, 1, 1, 0, -1};
//const int dc[] {0, 1, 1, 1, 0, -1, -1, -1};
typedef long long ll;
const int OO = 0x3f3f3f3f;
///-------------- may need them -----------------//
//int n;cin>>n;vector<int>ar(n);for(int &i:ar){cin>>i;}
//int dx[] = {2,-2,2,-2,1,1,-1,-1}, dy[] = {1,1,-1,-1,2,-2,2,-2}; // knight moves
//int dx[] = {0,0,1,1,1,-1,-1,-1}, dy[] = {-1,1,-1,0,1,-1,0,1}; // 8 adjacent neighbours
//int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0}; //4 adjacent neighbours
int const N = 3e5+5;
int const M = 2*N;
///---------------------------//
void main1()
{
  int n,x=0,y=0,eq=0;cin>>n;
  int a[n],b[n];
  for(int i=0;i<n;++i){
    cin>>a[i];
  }
  for(int i=0;i<n;++i){
    cin>>b[i];
    if((b[i] && a[i])||(!b[i] && !a[i]))
        eq++;
    else if(b[i] && !a[i])
        ++y;
    else
        ++x;
  }
  if(eq==n)
    cout<<"-1";
  else if(x>y)
    cout<<1;
  else if(x==y){
    for(int i=0;i<n;++i){
        if(a[i]!=b[i]){
            cout<<2;return;
        }
        cout<<-1;
    }
  }else{
      if(!x)
        cout<<-1;
      else cout<<(y/x)+1;
  }

}
int main()
{
    fast();
    int T=1;//cin>>T;
    //freopen("input.txt" ,"r" ,stdin);
    //freopen("output.txt" ,"w" ,stdout);
    while(T--) //cin.ignore();
    {
        main1();
        if(T)cout<<endl;
    }
    return 0;
}
