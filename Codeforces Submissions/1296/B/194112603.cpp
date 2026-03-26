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
        long long int count=0;
        long long int p = n;
        while(p>=10)
        {
            count+=p/10;
            p = p/10 + p%10;
        }
        cout<<n+count<<endl;
    }
    return 0;
}