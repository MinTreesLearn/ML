#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {

        int n, k;
        cin>>n >>k;

        vector <int> v(n);
        for (auto &it: v) cin>>it;
        sort(v.begin(), v.end());
        bool hobe=true;
        for (int i=1; i<n; i++) if (v[i]==v[i-1] && v[i]) {
                hobe=false;
                break;
            }
        vector <int> ktl(64, 0);

        if (hobe)
        {
            for (auto &it:v)
            {
                int i=0;
                while (it)
                {

                    ktl[i]+=it%k;
                    if(ktl[i]>1) {
                        hobe=false;
                        break;
                    }
                    it/=k;
                    i++;
                }
            if(!hobe) break;
            }

        }
        if(hobe) cout<<"YES\n";
        else cout <<"NO\n";

    }


}