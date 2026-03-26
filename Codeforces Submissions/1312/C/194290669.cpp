#include <bits/stdc++.h>
#include<iostream>
#include <conio.h>
typedef long long ll;
#define vec vector
#define pb push_back
#define lop(n) for(int i=0;i<n;i++)
#define lopj(n) for(int j=0;j<n;j++)
#define lop1(n) for(int i=1;i<=n;i++)
#define lopj1(n) for(int j=1;j<=n;j++)
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define yes(f) cout << (f?"YES":"NO") << endl
#define fast ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0)
using namespace std;

ll t, n, k, x , res , freq[100];
bool ans;
vec<ll> a;

bool getX(ll n)
{
    ll index = 0;
    while(n)
    {
        if(n%k > 1)
            return false;
        if(n%k)
            freq[index]++;
        n /= k;
        index++;
    }
    return true;
}

int main()
{

    cin >> t;
    while(t--)
    {
        a.clear();
        ans = true;
        res = 0;
        memset(freq , 0 , sizeof freq);
        cin >> n >> k;
        lop(n)
        {
            cin >> x;
            if(!getX(x))
                ans = false;
        }
        lop(100)
        {
            if(freq[i] > 1)
                ans = false;
        }
        yes(ans);
    }

    return 0;
}
