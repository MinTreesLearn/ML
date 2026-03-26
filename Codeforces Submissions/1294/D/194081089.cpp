#include<bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
#define pb emplace_back
#define mp make_pair
#define f first
#define endl '\n'
#define s second
#define all(c) (c).begin(), (c).end()
#define MOD 1000000007
long long mod(long long x)
{
    return ((x%MOD+MOD)%MOD);
}
long long add(long long a,long long b)
{
    return mod(mod(a)+mod(b));

}
long long mult(long long a,long long b)
{
    return mod(mod(a)*mod(b));
}


//RADHE RADHE
//Toh chaliye shuru karte hai bina kis bkc ke//

int main()
{

     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int q,x;
   cin>>q>>x;
   int mex=0;

   multiset<int>ms;
   while(q--)
   {
    int t;
    cin>>t;
    ms.insert(t%x);
    bool f=1;
    while(f)
    {
        int need=mex%x;
        auto it=ms.find(need);
        if(it!=ms.end())
        {
            mex++;
            ms.erase(it);
        }        
        else{
            f=0;
        }
    }
    cout<<mex<<endl;

   }
    return 0;
    //////////////////////////////////////HaStA La ViStA RoWdY's/////////////////////
}