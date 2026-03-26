#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s;
    cin>>s;
    while(s--)
    {
        int n=3;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        if(a[0]>=4)
        {
            cout<<"7"<<endl;
            continue;
        }
        if(a[0]==3)
        {
            cout<<"6"<<endl;
            continue;
        }
        if(a[0]==2)
        {
            if(a[2]==2)
                cout<<"4"<<endl;
            else
                cout<<"5"<<endl;
            continue;
        }
        if(a[0]==1)
        {
            if(a[1]==1)
                cout<<"3"<<endl;
            else
                cout<<"4"<<endl;
        }
        if(a[0]==0)
        {
            if(a[1]>=2)
            {
                cout<<"3"<<endl;
                continue;
            }
            if(a[1]==1)
            {
                cout<<"2"<<endl;
                continue;
            }
            if(a[1]==0)
            {
                if(a[2]==0)
                    cout<<"0"<<endl;
                else
                    cout<<"1"<<endl;
                continue;
            }
        }
    }
    return 0;
}