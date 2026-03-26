
#include <bits/stdc++.h>
using namespace std;
long long count(int a,int b)
{
    if(b<10)
    {
        return 0;
    }
    else
        {
            return a+count(a,b/10);
        }
}

void solve()
{
    int a,b;
    cin >> a >> b;
    int dub=b;
    int k=0;
    int d=0;
    while(dub)
    {
        d++;
        if(dub%10==9)
            k++;
        dub=dub/10;
        
    }
    if(k==d)
        cout << count(a,b)+a;
    else
        cout << count(a,b);
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
