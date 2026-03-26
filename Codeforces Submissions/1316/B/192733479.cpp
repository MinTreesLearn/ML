// Struggling
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
int arr[N], pf[N];
ll Mod = 1e9 + 7;
int is_prime[1000001];
void seive()
{
    int Max = 1000000;
    for (int i = 1; i <= Max; i++)
    {
        is_prime[i] = 1;
    }
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i * i <= Max; i++)
    {
        if (is_prime[i] == 1)
        {
            for (int j = i * i; j <= Max; j += i)
            {
                is_prime[j] = i;
            }
        }
    }
}
long long binpow(long long a, long long b)
{
    if (b == 0)
    {
        return 1ll;
    }
    long long res = binpow(a, b / 2ll);
    if (b % 2 == 1)
    {
        return (((((a % Mod) * (res % Mod)) % Mod) % Mod) * (res % Mod)) % Mod;
    }
    else
        return ((res % Mod) * (res % Mod)) % Mod;
}
int lenOfLongSubarr(int A[], int N, int K)
{
    int i = 0, j = 0, sum = 0;
    int maxLen = INT_MIN;
    while (j < N)
    {
        sum += A[j];
        if (sum < K)
        {
            j++;
        }
        else if (sum == K)
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else if (sum > K)
        {
            while (sum > K)
            {
                sum -= A[i];
                i++;
            }
            if (sum == K)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
    }
    return maxLen;
}
bool isPalindrome(string chker)
{
    int n = chker.size();
    for (int i = 0; i <= (n - 1) / 2; i++)
    {
        if (chker[i] != chker[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
float checkpow(int a, int b)
{
    return float(log2(a) / log2(b));
}
int lcsubstr(string str1, string str2)
{
    int ans = 0;

    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
        {
            int k = 0;
            while ((i + k) < str1.length() && (j + k) < str2.length() && str1[i + k] == str2[j + k])
            {
                k = k + 1;
            }

            ans = max(ans, k);
        }
    }
    return ans;
}
ll findClosestPerfectSquare(ll n)
{
    ll left = 0, right = 2000000123;
    while (left < right)
    {
        ll mid = (left + right) / 2;
        if (mid * mid <= n)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left - 1;
}
int GetBit(int n, int i)
{
    return ((n & (1 << i)) != 0);
}
int SetBit(int n, int i)
{
    return (n | (1 << i));
}
int ClearBit(int n, int i)
{
    return (n & (~(1 << i)));
}
int UpdateBit(int n, int i, int value)
{
    int mask = ~(1 << i);
    n = n & mask;
    return (n | (value << i));
}
int LIS(vector<int> &v)
{
    if (v.size() == 0)
    {
        return 0;
    }
    vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
        if (it == tail.begin() + length)
        {
            tail[length++] = v[i];
        }
        else
        {
            *it = v[i];
        }
    }
    return length;
}
void solve()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    string temp=str;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        string temp1=(str.substr(i+1,n-i-1));
        string temp2=(str.substr(0,i+1));
        if((n-i-1)&1)
        reverse(temp2.begin(),temp2.end());
        string s=temp1+temp2;
        if(s<temp)
        {
            temp=s;
            ans=i+2;
        }
    }
    if(ans==0)
    {
        ans++;
    }
    cout<<temp<<'\n';
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    // t = 1;
    seive();
    while (t--)
    {
        solve();
    }
    return 0;
}