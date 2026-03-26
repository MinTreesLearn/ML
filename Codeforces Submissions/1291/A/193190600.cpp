#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int s;
    cin>>s;
    while(s--)
    {
        long long int n;
        cin>>n;
        string a;
        cin>>a;
        long long int sum=0;
        for(long long int i=0;i<n;i++)
        {
            sum+=a[i]-48;
        }
        if(sum%2!=0 || a[n-1]%2==0)
        {
            int sum1=0,flag=-1;
            for(int i=0;i<n;i++)
            {
                sum1+=a[i]-48;
                if(sum1%2==0 && a[i]%2!=0)
                {
                    flag=i;
                    break;
                }
            }
            if(flag==-1)
            {
                cout<<-1<<endl;
                continue;
            }
            for(long long int i=0;i<=flag;i++)
                cout<<a[i];
            cout<<endl;
            continue;
        }
        cout<<a<<endl;
    }
    return 0;
}