#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char c;
    cin>>n>>c;
    string s(n,c);
    int x=0,y=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='L')
            x++;
        if(s[i]=='R')
            y++;
    }
    cout<<(x+y+1);

    return 0;
}
