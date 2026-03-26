 #include<stdio.h>
int main()
{
int t;
scanf("%d", &t);
while (t--)
{
long long n, m;
scanf("%lld %lld", &n, &m);
printf("%lld\n", (n/(m+1)+1)*(n/(m+1))/2*m+(n-n/(m+1)+1)*(n - n / (m + 1))/2);
}
}