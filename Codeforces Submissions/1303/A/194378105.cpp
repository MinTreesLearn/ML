//saw tutorial
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length(),i,j,k,l,m,c=0;
        for(i=0; i<n; i++)
        {
            if(s[i]=='1')
            {
                k=i;
                break;
            }
            else
            {
                k=-1;
            }
        }
        for(j=n-1; j>=0; j--)
        {
            if(s[j]=='1')
            {
                m=j;

                break;
            }
            else
            {
                m=-1;
            }

        }
        if(k==-1 && m==-1)
        {
            cout<<0<<endl;
        }
        else
        {
            for(l=k; l<=m; l++)
            {
                if(s[l]=='0')
                {
                    c++;
                }
            }

            cout<<c<<endl;
        }

    }
    return 0;
}
