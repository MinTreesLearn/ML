#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    long long n;
    cin>>n;
    string s;
    cin>>s;

    long long i=0,ct=0,ans=0;
    while (n--)
    {
        if(s[i]=='('){ct++;}
        else if(s[i]==')'){ct--;}
        if(ct<0 || (ct==0 && s[i]=='('))
        {
            ans++;
        }
        i++;
    }
    if(ct!=0)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<ans<<"\n";
    }
    
}

