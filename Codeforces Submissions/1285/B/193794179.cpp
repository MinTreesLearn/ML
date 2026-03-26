#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;cin>>t;
    while(t--)
    {
        map<long long,long long> mp;
        long long n;cin>>n;
        vector<long long> v(n);
        long long s1=0,sum=0;
        long long maxi= LONG_LONG_MIN;
        long long neg=0;
        for(long long i=0;i<n;i++)
        {
            cin>>v[i];
           
            s1+=v[i];
            sum+=v[i];
            if(maxi<=sum)
            {
                mp[sum]++;
                maxi=sum;
            }
            
            if(sum<0)
            {
                sum=0;
                neg++;
            }
            else if(sum==0)
            neg++;
        }
        // cout<<maxi<<"\n";
        // cout<<mp[maxi]<<"\n";
        if(s1==maxi && neg==0 && mp[maxi]==1)
        cout<<"YES\n";
        else if(s1>maxi)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}