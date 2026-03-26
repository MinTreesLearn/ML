// LUOGU_RID: 93154108
#include<cstdio>
#define ll long long
using namespace std;
char s[1005];
int pos = 0, trie[1000005][26], siz[1000005], dfn[1000005], fir[1005];
__int128 sdp[1005][1005];
void dfs(int p)
{
	dfn[p] = ++pos, siz[p] = 1;
	for(int i = 0; i < 26; i++)
		if(trie[p][i])
			dfs(trie[p][i]), siz[p] += siz[trie[p][i]];
}
void prt(int p, int n)
{
	if(dfn[p] == n) return;
	for(int i = 0; i < 26; i++)
		if(trie[p][i] && dfn[trie[p][i]] + siz[trie[p][i]] - 1 >= n)
		{
			putchar(i + 'a');
			prt(trie[p][i], n);
			break;
		}
}
int main()
{
	int n, m, p0, sum = 1, l = 1, r, mid;
	ll k;
	__int128 tmp;
	scanf("%d%d%lld", &n, &m, &k);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
	{
		p0 = 1;
		for(int j = i; j <= n; j++)
		{
			if(!trie[p0][s[j] - 'a'])
				trie[p0][s[j] - 'a'] = ++sum;
			p0 = trie[p0][s[j] - 'a'];
		}
	}
	dfs(1);
	r = sum;
	while(l < r)
	{
		mid = (l + r) / 2;
		for(int i = 1; i <= n; i++)
		{
			fir[i] = n + 1, p0 = 1;
			for(int j = i; j <= n; j++)
			{
				p0 = trie[p0][s[j] - 'a'];
				if(dfn[p0] > mid)
				{
					fir[i] = j;
					break;
				}
			}
		}
		for(int i = 1; i <= n + 1; i++)
			sdp[i][0] = 1;
		for(int i = 1; i <= m; i++)
			for(int j = n; j; j--)
			{
				tmp = sdp[fir[j] + 1][i - 1];
				if(tmp >= k) tmp = k;
				sdp[j][i] = sdp[j + 1][i] + tmp;
			}
		if(sdp[1][m] - sdp[2][m] >= k) l = mid + 1;
		else r = mid;
	}
	prt(1, l);
	return 0;
}