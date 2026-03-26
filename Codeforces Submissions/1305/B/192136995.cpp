#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    int n = s.length();
    vector<int> a;
    vector<int> b;
    int close=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==')')
        {
            b.push_back(i);
            close++;
        }
        else
        a.push_back(i);
    }    
    if(close==0)
    {
        cout<<0<<"\n";
        return 0;
    }
    int c=0;
    int ma=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        c++;
        else
        close--;
        
        if(s[i]=='(' && close>=c)
        ma  =max(ma,c);
    }
    if(ma==INT_MIN)
    {
        cout<<0<<"\n";
        return 0;
    }
    cout<<1<<"\n";
    cout<<ma*2<<"\n";
    reverse(b.begin(),b.end());
    vector<int> ans;
    for(int i=0;i<ma;i++)
    {
        ans.push_back(a[i]+1);
        ans.push_back(b[i]+1);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<"\n";
    
}