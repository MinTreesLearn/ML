#include <iostream>
#include <algorithm>
using namespace std;
int a[110];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
