#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long ll;
#define vi vector<int>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    double a=0;
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) a=a+(double)1/i;
    
    cout << fixed << setprecision(12) << a << endl;
    

    return 0;
}