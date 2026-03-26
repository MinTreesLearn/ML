#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ff first
#define ss second
#define popf pop_front
#define popb pop_back
#define pb push_back
#define pf push_front
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define go   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


const int N=2e5+10;
//int a[1000][1000];
int a[N];


map<char,vector<int> > m;
map<char,vector<int> > m2;
vector<pair<int,int>>v;
int32_t main( )
{
    go

    int t=1;



    //cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        string s,s2;
        cin>>s>>s2;
        for( int i=0; i<n; i++)
        {
            m[ s[i]  ].pb(i+1);
            m2[ s2[i]  ].pb(i+1);
        }
        for(auto i:m)
        {
            if( i.ff=='?')continue;
            if( m2[i.ff].size() )
            {
                while( m[i.ff].size() && m2[i.ff].size() )
                {
                    v.pb( { m[i.ff].back(),m2[i.ff].back() }  );
                    m[i.ff].popb();
                    m2[i.ff].popb();
                }

            }
            if(     m2['?'].size())
            {
                while( m[i.ff].size() && m2['?'].size() )
                {
                    v.pb( { m[i.ff].back(),m2['?'].back() }  );
                    m[i.ff].popb();
                    m2['?'].popb();
                }
            }

        }
        for(auto i:m2)
        {
            if( i.ff == '?')
            {
                for(auto j:m)
                {
                    if( j.ss.size() )
                    {
                        while( m[ j.ff ].size() && m2['?'].size()  )
                        {
                            v.pb( { m[j.ff].back(),m2['?'].back() } );
                            m2['?'].popb();
                            m[j.ff].popb();

                        }

                    }
                }

            }
            if(  i.ss.size())
            {
                while( m['?'].size() && m2[i.ff].size() )
                {
                    v.pb( {  m['?'].back(), m2[i.ff].back()  }  );
                    m['?'].popb();
                    m2[i.ff].popb();
                }

            }
        }

        cout<<v.size()<<endl;
        for(auto i:v) cout<<i.ff<<" "<<i.ss<<endl;

    }
}




/**

  /// (a-b)%mod == ( (a-b)%mod+ mod)%mod

///   mod  inverse  n!/k!=  n!*pow(k!,mod-2);


// count the number of numbers in range A , B that are divisible by M
int cnt( int A , int B , int M)
{
    if(A%M  == 0) return B/M - A/M +1 ;
    else return B/M - A/M  ;

}
// mod inverse :

int inv( int d)
 {
     return power(d,mod-2,mod);
 }


bool isreg( string s)
{
    vector<char>v;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(') v.push_back('(');
        else if(s[i]==')'&&v.size()) v.pop_back();
        else if( s[i]==')'&&v.size()==0  )return 0;


    }
    if(v.size())return 0;
    return 1;


}

void seive()
{
    for( int i=0; i<N; i++) prime[i]=1;
    prime[1]=0;
    prime[0]=0;
    for( int i=2; i*i<=N; i++)
    {
        if( prime[ i ] )
        {
            for( int j=2; j*i<=N; j++)
            {
                prime[i*j]=0;

           }
        }
    }

}
string numToString(long long n)
{
    string s="";
    while( n>0)
    {
        s+=n%10+48;
    n/=10;
    }

    reverse(s.begin(),s.end());
    return s;
}


int decToBinary( ll n , int arr[])
{

    for(int i=0;i<100;i++)arr[i]=0;
    int i=0;
    while(n)
    {
        arr[i]=n%2;
        n/=2;
        i++;
    }
// reverse( arr,arr+32);
    return i;

}

int stn( string s )
{
    int now=0;
    for( auto i:s)
    {
        now+=i-48;
        now*=10;
    }
    now/=10;
    return now;
}


ll power(ll a,ll b  )
{
    if(b==0)return 1;
    ll res=power(a,b/2 );
    if(b%2)
        return(((res * res) )*(a) );
    else
        return (res*res) ;


}
// power with mod

ll power(ll a ,ll b , ll m)
{
   if(b==0)return 1;
ll res=power(a,b/2,m);
   if(b%2)
    return(((res * res)%m)*(a%m) )%m;
   else
    return (res*res)%m;


}



/// we  have pair  , and we want to sort it in ascending order by its first and in descending order by its second :
 int now=v[0].ff;
    int l=0,r=0;
        sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)
    {
        if( now==v[i].ff  )
        {
            r++;
        }
        else
        {
            reverse( v.begin()+l,v.begin()+r+1 );
            now=v[i].ff;
            l=r=i;
        }
        if( i== v.size()-1)
        {
             reverse( v.begin()+l,v.begin()+r+1 );
        }

    }

*/
