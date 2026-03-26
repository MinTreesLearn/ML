#include<iostream>
using namespace std;
using ll = long long int ;
int main()
{
    ll t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
     int n;
        cin>>n;
        string s;
        string ss="";
        cin>>s;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9')
                ss+=s[i];
            if(ss.size()==2)
                break;
        }
        if(ss.size()==2)
            cout<<ss<<endl;
        else cout<<-1<<endl;
        

    }
    return 0;
}