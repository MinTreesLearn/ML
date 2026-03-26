#include<bits/stdc++.h>

using namespace std;

#define vt vector
#define pb push_back
#define ll long long
#define sz(x) (int)(x).size
#define all(x) (x).begin(),(x).end()
#define allb(x) (x).rbegin(),(x).rend()

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

const int mxm=1e9+7;
const int mx=2e5+5;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void get_accepted(){
	int dp[63]={0};
	ll n,m;
	cin>>n>>m;
	int a[m];
	ll sum=0;
	for(int i=0;i<m;i++){
		cin>>a[i];
		sum+=(ll)a[i];
		int x=a[i];
		int cunt=0;
		while(x!=1){
			x/=2;
			cunt++;
		}
		dp[cunt]++;
	}
	if(sum<n){
		cout<<"-1\n";
		return;
	}
	ll r=n;
	int ans=0;
	for(int i=0;i<=60;i++){
		int e=r%2;
		r/=2;
		if(e==1){
			if(dp[i]>0){
				dp[i]--;
				goto label;
			}
			else{
				ans++;
				int j;
				for(j=i+1;j<=60;j++){
					if(dp[j]>0){
						dp[j]--;
						break;
					}
					ans++;
				}
				for(int u=i;u<j;u++){
					dp[u]++;
				}
			}
		}
		else{
			label:
			dp[i+1]+=dp[i]/2;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tt;
	cin>>tt;
//	tt=1;
	while(tt--){
		get_accepted();
	}
}

