// LUOGU_RID: 102499094
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        int x[3]={0,0,0},len=0;
        for(int j=2;j*j<=n;j++)
        {
            if(n%j==0)
            {
                x[0]=j;
                break;
            }
        }
        if(x[0]==0)
        {
            cout<<"NO\n";
            continue;
        }
        n/=x[0];
        for(int j=x[0]+1;j*j<=n;j++)
        {
            if(n%j==0)
            {
                x[1]=j;
                break;
            }
        }
        if(x[1]==0)
        {
            cout<<"NO\n";
            continue;
        }
        n/=x[1];
        if(n!=x[1]&&n!=x[0]&&n>=1)
        {
            cout<<"YES\n";
            cout<<x[0]<<" "<<x[1]<<" "<<n<<endl;
            continue;
        }
        cout<<"NO\n";
    }
}