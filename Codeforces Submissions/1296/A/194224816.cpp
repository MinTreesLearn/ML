#include <bits/stdc++.h>
const long long mod = 1000001;
#define ll long long int
#define in(k) \
    int k;    \
    cin >> k
#define i(a, b) \
    int a, b;   \
    cin >> a >> b
#define inp(arr, n)             \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define f(i, a, b) for (int i = a; i < b; i++)
#define no cout << "NO"
#define yes cout << "YES"
#define nl cout << "\n"
#define maxi(a, n) *max_element(a, a + n)
#define mini(a, n) *min_element(a, a + n)
#define Sort(a, n) sort(a, a + n, greater<int>())
#define print(a, n)             \
    for (int i = 0; i < n; i++) \
    cout << a[i] << " "
#define vi vector<int>
#define vll vector<ll>
#define ff first
#define ss second
#define pb push_back
#define sum(arr, n) accumulate(arr, arr + n, 0)
#define mii map<int, int>
#define bione __builtin_popcount

#define ppb pop_back
#define mp make_pair
#define ss second
#define ff first
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define debug(x) cout << #x << " : " << x << endl;
#define debugarr(a, x) cout << #a << "[" << x << "]" \
                            << " : " << a[x] << endl;

#define clock cerr << "Time elapsed: " << 1000 * 1.0 * clock() / CLOCKS_PER_SEC << " ms.\n";

using namespace std;
int gcd(int A, int B)
{
    if (B == 0)
        return A;
    else
        return gcd(B, A % B);
}

int SOD(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum = sum + n % 10;
        n /= 10;
    }
    return sum;
}

int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int pow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return (int)res;
}
int pow(int x, int y, int p) // Modular Exponentiation
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

string dectobin(int x) // Decimal To Binary
{
    string s = "";
    while (x > 0)
    {
        int t = x % 2;
        s.pb(t + '0');
        x /= 2;
    }
    reverse(s.begin(), s.end());
    if (s.compare("") == 0)
        return "0";
    else
        return s;
}

int bintodec(string s) // Binary To Decimal
{
    int ans = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            ans += pow(2, n - i - 1);
    }
    return ans;
}

bool isPalindrome(string s)

{

    ll low = 0;
    ll high = s.length() - 1;

    while (low < high)
    {
        if (s[low] != s[high])
        {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

bool isPrime[mod] = {true};

void SieveOfEratosthenes()
{
    memset(isPrime, true, sizeof(isPrime));
    for (ll p = 2; p * p <= mod; p++)
    {
        if (isPrime[p] == true)
        {
            for (ll i = p * 2; i <= mod; i += p)
                isPrime[i] = false;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] % 2;
        if (a[i] == 1)
        {
            odd++;
        }
    }
    if (sum % 2 == 1)
    {
        cout << "YES\n";
    }
    else
    {
        if (odd > 0 and odd < n)
            cout << "YES\n";

        else
            cout << "NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    in(t);
    while (t--)
    {
        solve();
    }
}