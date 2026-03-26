#include <bits\stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long  t,i,j,p=0,q=0;


        int n;
        cin >> n;
        long long a[n], b[n] ,d[n],c[200005]={0};

        for (i=0;i<n ;i++)
        {
            cin >> a[i];
        }
         for (i=0;i<n ;i++)
        {
            cin >> b[i];
            c[i] = a[i] - b[i];
            d[i] = c[i];
        }
       sort (c,c+n);
          q = 0;
       for (i=0;i<n ;i++)
       {
      p =  upper_bound(c,c+n,(d[i]*(-1)))-c;
      if (d[i]<=0)  q+= (n-p); else q+= n-p-1;
       }   cout << q/2 << endl;

    return 0;
}
