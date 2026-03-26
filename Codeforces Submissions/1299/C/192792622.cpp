#include<bits/stdc++.h>
using namespace std;
const int o=1e6+3;
int n,b[o],q;
double a[o];
signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
for (int i=1,y,z;i<=n;i++){
double x;
cin>>z,x=z,y=1;
while (q&&a[q]/b[q]>x/y)
x+=a[q],y+=b[q],q--;
a[++q]=x,b[q]=y;
}
for (int i=1;i<=q;i++)
for (int j=1;j<=b[i];j++)
cout<<fixed<<setprecision(10)<<a[i]/b[i]<<"\n";
return 0;
}
