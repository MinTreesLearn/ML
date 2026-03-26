#include<bits/stdc++.h>
#define sortall(v) sort(v.begin(), v.end())
#define reverse(allv) reverse(v.begin(), v.end())
#define rall(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define mk make_pair
using namespace std;

void d1zzaster1(){
	string a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < (int)a.size(); i++){
    	if(c[i] != a[i] && c[i] != b[i]){
    		cout << "NO\n";
    		return;
		}
	}
	cout << "YES\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--){
    	d1zzaster1();
	}
}