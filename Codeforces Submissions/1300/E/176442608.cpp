#include <bits/stdc++.h>
#define ll long long
#define sys system("pause");
#define re register
using namespace std;
deque<pair<double, int>> q;
int main()
{
    re int n, cnt;
    re double sum;
    scanf("%d", &n);
    for (re int i = 1; i <= n; ++i)
    {
        scanf("%lf", &sum);
        cnt = 1;
        while (q.size() && (q.front().first + sum) / (q.front().second + cnt) < q.front().first / q.front().second)
            sum += q.front().first, cnt += q.front().second, q.pop_front();
        q.push_front({sum, cnt});
    }
    re pair<double, int> pi;
    while (q.size())
    {
        pi = q.back();
        q.pop_back();
        pi.first = pi.first / pi.second;
        while (pi.second--)printf("%.9lf\n", pi.first);
    }
    // sys;
    return 0;
}
