//author: TomoriNao
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ll long long
//#include<time.h>
using namespace std;

int main(){
  //  freopen("1.inp","r",stdin);
//freopen("1.ans","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin >>t;
while (t--)
{
  ll a; string b;
    cin >>a>>b;
 bool ok = true;
 for (int i =0;i<b.size();i++)
 {
     if (b[i]-'0'<9)
     {
         ok = false;
         break;
     }
 }
 int so =0;
 if (ok)
 {
     so =b.size();
 }
 else
 {
     so =b.size()-1;
 }
 ll sodau=1;

 cout <<a*so<<endl;


}
    return 0;
}
