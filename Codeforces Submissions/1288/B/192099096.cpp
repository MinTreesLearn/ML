#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solution()
{
    ll int A,B;
    cin >> A >> B;
    ll int b=9;
    ll int count=0;
    ll int p=0;
    while(b<=B){
        count+=A;
        p++;
        b+=9*pow(10,p);
        // cout<<b<<endl;
    }
    cout<<count<<endl;
}
int main()
{
    // Makes input and output fast
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    // Test cases
    int T;
    cin>>T;
    while(T--)
        solution();
    return 0;
}