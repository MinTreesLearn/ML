#include<bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long s;
cin>>s;
while(s--)
{  long long l;
    cin>>l;
    long long s[l+2];
    for(long long q=0;q<l;q++)
        cin>>s[q];
    sort(s,s+l,greater<long long>());
    for(long long q=0;q<l;q++)
        cout<<s[q]<<" ";
    cout<<endl;
}

return 0;
}


