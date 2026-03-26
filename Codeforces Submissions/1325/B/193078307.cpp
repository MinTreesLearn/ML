#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        set<int> s;
        while (n--)
        {
            int a;
            scanf("%d",&a);
            s.insert(a);
        }
        printf("%d\n",s.size());
    }
}
