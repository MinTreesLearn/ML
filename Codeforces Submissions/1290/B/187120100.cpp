#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int maxn=2*1e5+11;
const int Maxx=5*1e5+11;
const int mod=1e9+7;
int t;
string s;
int q;
int l,r;
int pre[maxn][30];
void solve()
{
     cin>>s;
     for(int i=0;i<s.size();++i)
     {
         for(int j=1;j<=26;++j) pre[i+1][j]=pre[i][j];
         ++pre[i+1][int(s[i]-'a')+1];
     }
     cin>>q;
     while(q--)
     {
         cin>>l>>r;
         --l,--r;
         if(s[l]!=s[r])
         {
             cout<<"Yes"<<endl;continue;
         }
         if(l==r) {cout<<"Yes"<<endl;continue;}
         ++l,++r;
         int num=0;
         for(int i=1;i<=26;++i)
         {
              if(pre[r][i]-pre[l-1][i]) ++num;
         }
         if(num>=3) {cout<<"Yes"<<endl;continue;}
         else {cout<<"No"<<endl;continue;}
     }
}
int main()
{
    //scanf("%d",&t);
    ios::sync_with_stdio(false);cin.tie(0);
    //ios::sync_with_stdio(false);cin.tie(0);cin>>t;while(t--)
        solve();
    return 0;
}