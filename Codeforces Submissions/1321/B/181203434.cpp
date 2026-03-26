#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int N = 2e5 + 20;

int n;
LL a[N], b[N], x;
map <LL, LL> h;

int main()
{
    LL ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%lld", a + i);
    for(int i = 1; i <= n; i ++) 
    {
        h[a[i] - i] += a[i];
        ans = max(ans, h[a[i] - i]);
    }
    

    printf("%lld\n", ans);
    return 0;
}

	  		 			  		         			 	 	