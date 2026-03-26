/*====================	BISMILLAHIR RAHMANIR RAHIM	===============*/

/*
────────────────╔═╗─╔╗────╔═══╦╗────────╔╗────────────────────────
────────────────║║╚╗║║────║╔═╗║║────────║║────────────────────────
────────────────║╔╗╚╝╠╗╔╦═╣║─║║║╔══╦╗╔╗─║╠══╦╗─╔╗ ────────────────
────────────────║║╚╗║║║║║╔╣╚═╝║║║╔╗║╚╝╠╗║║╔╗║║─║║ ────────────────
────────────────║║─║║║╚╝║║║╔═╗║╚╣╔╗║║║║╚╝║╚╝║╚═╝║ ────────────────
────────────────╚╝─╚═╩══╩╝╚╝─╚╩═╩╝╚╩╩╩╩══╩══╩═╗╔╝ ────────────────
────────────────────────────────────────────╔═╝║ ─────────────────
────────────────────────────────────────────╚══╝ ─────────────────
*/

#include<bits/stdc++.h>
using namespace std;
#define FASTER() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long int
#define pb push_back
#define mp make_pair
#define all v.begin(),v.end()
#define rall v.rbegin(),v.rend()
#define in insert
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define gcd __gcd
#define fr(i,a,b) for(ll i=a;i<b;i++)
ll lcm( ll a, ll b ) {return (a*b)/gcd(a,b);}
typedef __int128 lll;
const ll mod=1e9+7;

void solve(int t)
{

	int n , d;
	cin >> n >> d;
	vector<int>v(n);
	for(int i=0; i<n; i++)cin>> v[i];
	for( int i=1; i<n; )
	{
		if(v[i]>0 && (d-i)>=0)
		{
			v[0]++;
			d-=i;
			v[i]--;
		}
		else i++;
	}
	cout << v[0] << endl;
	

}
 

int main()
{
	FASTER();
	
	int t;
	cin >> t;
	while(t--)
	{
		solve(t);
	}

 
	return 0;
}