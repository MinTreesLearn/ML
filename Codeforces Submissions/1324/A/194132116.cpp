#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,even=0,odd=0;
        cin>>n;
        int a[n];
        for( i=0;i<n;i++)

            cin>>a[i];
            for(i=0;i<n;i++)
            {
                if(a[i]%2==0)
                    even=1;
                else
                    odd=1;
            }
            if(even+odd==1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
    }
}

