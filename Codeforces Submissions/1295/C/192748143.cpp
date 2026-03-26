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
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
int q,j=0;
cin>>q;
int arr[q];
while(j<q){

            str s1,s2;
            cin>>s1>>s2;
            vector<int> ind(26,-1);
            int vec[s1.sz][26];

            


            for (int i = s1.sz - 1; i >= 0; i--)
            {
                int d = s1[i]-'a';
                for (int ii = 0; ii < 26; ii++)
                {
                    vec[i][ii]=ind[ii];
                }
                ind[d]=i;
                
            }



            int st=0;
            int op=0;

            while (st<s2.sz)
            {
                int beg=0;
                int d = s2[st]-'a';
                
                beg=ind[d];
                if (beg==-1)
                {
                    op=-1;
                    break;
                }
                st++;

                while (st<s2.sz)
                {
                    int dd = s2[st]-'a';
                   if (vec[beg][dd]==-1)
                   {
                      break;
                   }
                   else
                   {
                      beg = vec[beg][dd];
                      st++;
                   }
                   
                   
                }
                op++;
                
                


                
            }
            

           
                
                

            cout<<op<<endl;
            




            
                        
                              
j++;
}
return 0;
}