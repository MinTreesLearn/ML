#include <bits/stdc++.h>


using namespace std;

const int maxc = 5005;

int64_t k[maxc] = {0};
int64_t pr[maxc] = {0};
int64_t km[maxc] = {0};
int64_t md[maxc] = {0};
int64_t np[maxc] = {0};

int main()
{
    int n;
    cin >> n;
    for(int i =2;i < maxc;++i)
    {
        for(int j = i;j < maxc;j+=i)
        {
            if(md[j] == 0)
            {
                md[j] = i;
            }
        }
        km[i] = km[i/md[i]] + 1;
    }
    for(int i =0;i < n;++i)
    {
        int x;
        cin >> x;
        if(x == 0)
            x = 1;
        k[x]++;
    }
    pr[0] = 0;
    for(int i =1;i < maxc;++i)
    {
        pr[i] = pr[i-1] + k[i];
    }
    int64_t ans = 0;
    int64_t tk = 0;
    for(int i = 1;i < maxc;++i)
    {
        tk += km[i];
        ans += k[i]*tk;
    }
    int64_t lp = -1;
    int64_t kc = 0;
    int64_t div = -1;
    int64_t l = -1,r = -1;
    for(int i = 2;i < maxc;++i)
    {
        if(km[i] == 1)
        {
            np[i] = lp;
            if(kc > n/2)
            {
                ans += n-kc;
                ans-=kc;
                div = lp;
                l = lp;
                r = i-1;
                break;
            }
            kc = 0;
            lp = i;
        }
        kc += k[i];
    }
    if(div == -1)
    {
        cout << ans << "\n";
        return 0;
    }
    else
    {
        int64_t ld = div;
        int64_t cc= 1;
        while(true)
        {
            int64_t l2 = l,r2 = r+1;
            while(l2 < r2)
            {
                int64_t m2 = (l2+r2)/2;
                int64_t kc = 0;
                for(int64_t i = ld;i <= m2;i*=ld)
                {
                    kc += m2/i;
                }
                if(kc <= cc)
                    l2 = m2+1;
                else
                    r2 = m2;
            }
            if(ld != 2 && pr[l2-1]-pr[l-1] > n/2)
            {
                ans += n-2*(pr[l2-1]-pr[l-1]);
                ld = np[ld];
                cc = 1;
                r = l2-1;
            }
            else if(pr[r]-pr[r2-1] > n/2)
            {
                ans += n-2*(pr[r]-pr[r2-1]);
                cc++;
                l = r2;
            }
            else
                break;
        }
        cout << ans << "\n";
    }
}
