#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <bitset>
#include <map> 
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mem(a, b) memset(a, b, sizeof(a));
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); //勿混用
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int M = 1e5 + 5;
///////////////////////////////////////////////
int n, m;
double x[N], y[N];

int ff(int i)
{
    double a, b;
    int ax, bx;
    ax = y[i + 1] - y[i];
    a = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
    i += n / 2;
    bx = y[i] - y[i + 1];
    b = (y[i] - y[i + 1]) / (x[i] - x[i + 1]);
    if (abs(a - b) < 0.00000001 && ax == bx) return 0;
    return 1;
}

int main() {
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];
    if (n % 2)
    {
        cout << "no"; return 0;
    }
    int flog = 1;
    int ax, bx;
    double a, b;
    ax = y[n / 2] - y[n / 2 + 1];
    bx = y[1] - y[n];
    a = (y[n / 2] - y[n / 2 + 1]) / (x[n / 2] - x[n / 2 + 1]);
    b = (y[1] - y[n]) / (x[1] - x[n]);
    if (abs(a - b) > 0.000000001 || ax != bx)
        flog = 0;
    else
        for (int i = 1; i < n / 2; ++i)
        {
            if (ff(i))
            {
                flog = 0;
                break;
            }
        }

    if (flog) cout << "YES";
    else cout << "no";
    return 0;
}
  	  		 	 		 	 	  			 	    		