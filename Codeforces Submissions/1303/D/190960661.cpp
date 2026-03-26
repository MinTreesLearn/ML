#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    vector<unsigned> bs((int)1e5);
    vector<unsigned> ps(65, 0);
    while (t--)
    {
        unsigned long long n,k; cin >> n >> k;
        long long sum = 0;
        unsigned res = 0;
        for(int i = 0; i < k; ++i)
        {
            cin >> bs[i];  
            sum += bs[i];
            ++ps[31 - __builtin_clz(bs[i])];
        }
        if(sum < n)
        {
            cout << -1 << '\n';
        }
        else
        {
            for(int i = 0; i < 64; ++i)
            {
                auto bit = (1ll << i) & n;
                if(bit == 0)
                {
                    ps[i+1] += ps[i]/2;
                }
                else if(bit != 0 && ps[i] > 0)
                {
                    --ps[i];
                    ps[i+1] += ps[i]/2;
                }
                else if(bit != 0 && ps[i] == 0)
                {
                    int j = i;
                    while(ps[j] == 0) ++j;
                    while(j != i)
                    {
                        --ps[j];
                        ps[j-1] += 2;
                        --j;
                        ++res;
                    }
                    --ps[i];
                    ps[i+1] += ps[i]/2;

                    
                }
            }
            cout << res << "\n";
        }
        fill(ps.begin(), ps.end(), 0);
    }
    
}