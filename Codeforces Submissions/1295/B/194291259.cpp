                                        //Your worst fear owns this
#include <bits/stdc++.h>
#define ll long long int
#define srv(v) sort(v.begin(),v.end())
#define rrv(s1) sort(s1.begin(),s1.end(),greater<ll>())
#define str string
#define sz size()
#define dv(v) vector<ll> v
#define ds(s) set<ll> s
#define dm(mp) map<ll,ll> mp
#define debug(x)  cout<<#x<<" "<<x<<endl
#define MOD 1000000007
int binpow(int a, int b){if (b==1){return a;}else if (b==0){return 1;}ll one = binpow(a,b/2);if (b%2==0){return one*one;}else{return a*one*one;}}
using namespace std;
int main()
{
 
int q,j=0;
cin>>q;
int arr[q];
while(j<q){

      ll n,m;
      cin>>n>>m;

      str s;
      cin>>s;
      ll one=0,zero=0;
      ll xxx=0;
        if ((zero-one)==m)
        {
           xxx++;
        }

      for (ll i = 0; i < n; i++)
      {
        if (s[i]=='1')
        {
            one++;
        }
        else
        {
            zero++;
        }

        if ((zero-one)==m)
        {
           xxx++;
        }
        
        
        
      }

      // 10 12   20 24   30 36

      ll cost = zero-one;
      if (zero==one&&xxx>0)
      {
        // cout<<'g';
        cout<<-1<<endl;
        j++;
        continue;
      }
      else if (cost==0)
      {
          ll o=0,z=0;
          ll op=0;

          if ((z-o)==m)
          {
            op++;
          }
          
          for (ll i = 0; i < s.sz; i++)
          {
            if (s[i]=='1')
            {
                o++;
            }
            else
            {
                z++;
            }

            if ((z-o)==m)
            {
               op++;
            }
            
            
            
          }

          cout<<op<<endl;
          j++;
          continue;
          
      }

    //   cout<<cost<<endl;

     ll pp = cost*m;
    //  cout<<m<<endl;

    //  cout<<pp<<endl;
      
      

      if (1>=0)
      {
         ll c=cost;
         ll o=one;
         ll z=zero;
         ll st=2;
         
         o=0,z=0;
         ll op=0;

        //  if (m%cost==0)
        //  {
        //     op++;
        //  }
        // cout<<'g';

        if (m==0)
        {
          op++;
        }
        
         

         for (int i = 0; i < s.sz; i++)
         {
             if (s[i]=='1')
             {
               o++;
             }
             else
             {
                z++;
             }
             
             int cx = z-o;

             int mm = m-cx;
            //  cout<<mm<<" "<<c<<endl;

             if (mm*c>=0)
             {
                /* code */
             
             

             
                if (mm%c==0)
                {
                   op++;
                }
             }
                
            //  }
             
             
         }

         cout<<op<<endl;
         

         



         
      }
      else
      {
        // cout<<'g';
           int op=0;
           if (m==0)
           {
             op++;
           }
           int z=0,o=0;
           
           for (int i = 0; i < s.sz; i++)
           {
              if (s[i]=='1')
              {
                o++;
              }
              else
              {
                z++;
              }

              if ((z-o)==m)
              {
                op++;
              }
              
              
              
           }

           cout<<op<<endl;
           
      }
      
      


      
                        
                              
j++;
}
return 0;
}