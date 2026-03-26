#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define vi vector<int>
int main()
{
ios_base::sync_with_stdio(0);
 cin.tie(NULL);
 int t;
 cin>>t;
 while (t--)
 {
    int n,p,c;
    cin>>n>>p>>c;
    int a[c];
    for(int i=0;i<c;i++)cin>>a[i]; 
    for(int i=0;i<=c;i++){
        if (p - i >= 1 && find(a, a+c, p - i) == &a[c-1]+1) {
            cout<<i<<endl;
            break;
        }
        else if (p + i <= n && find(a, a + c, p + i) == &a[c - 1]+1)
        {
            cout << i << endl;
            break;
        }
        
    }
 

 
}

}