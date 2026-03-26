#include <bits/stdc++.h>
#define ll long long
#define sys system("pause");
using namespace std;
deque<pair<double,int>> q;
int main()
{
    int n;
    double x;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lf",&x);
        double sum=x,cnt=1;
        while(q.size()&&(q.front().first+sum)/(q.front().second+cnt)<q.front().first/q.front().second)
            sum+=q.front().first,cnt+=q.front().second,q.pop_front();
        q.push_front({sum,cnt});
    }
    while(q.size())
    {
        pair<double,int> pi=q.back();
        q.pop_back();
        x=pi.first/pi.second;
        while(pi.second--)
        {
            printf("%.9lf\n",x);
        }
    }
    sys;
    return 0;
}
