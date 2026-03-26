#include<iostream>
using namespace std;
using ll=long long int;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    ll cnt=0,k=0,sum=0;
    ll n;
    string s, s1;

    cin>>n;
    if(n%2  and n>=3)s+='7', n-=3;

    while(n>1 and n%2==0)
    {
        s1+='1';
        n-=2;
    }
    //debug;
    s+=s1;
    cout<<s<<endl;

    }

return 0;
}