#include <bits/stdc++.h>
long long t,a,m,ans;
int main() {
for(scanf("%lld",&t);t--;) {
scanf("%lld%lld",&a,&m);ans=m/=std::gcd(a,m);
for(long long i=2;i*i<=m;i++)if(m%i==0)
for(ans-=ans/i;m%i==0;m/=i);
printf("%lld\n",ans-(m>1)*ans/m);
}
}