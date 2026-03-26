// LUOGU_RID: 94145794
#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
char s1[500005], s2[500005], s3[1000005], s4[1000005];
int z1[500005], z2[500005], z3[1000005], z4[1000005];
void calcz(int n1, int n2, char s1[], int z1[], char s2[], int z2[])
{
	int pos = 0;
	if(s1 == s2) z2[1] = n2;
	for(int i = 1 + (s1 == s2); i <= n2; i++)
	{
		z2[i] = min(z2[pos] - (i - pos), z1[i - pos + 1]);
		if(z2[i] < 0) z2[i] = 0;
		while(s2[i + z2[i]] == s1[z2[i] + 1]) z2[i]++;
		if(i + z2[i] > pos + z2[pos]) pos = i;
	}
} //1 -> 2
ll fw1[1000005], fw2[1000005];
void fwadd(ll fw[], int n, int p, ll t){while(p <= n) fw[p] += t, p += p & -p;}
ll fwget(ll fw[], int p){ll res = 0; while(p) res += fw[p], p -= p & -p; return res;}
void modify(int n, int l, int r, ll t)
{
	fwadd(fw1, n, l, t * l), fwadd(fw1, n, r + 1, -t * (r + 1));
	fwadd(fw2, n, l, t), fwadd(fw2, n, r + 1, -t);
}
ll get(int n, int l, int r)
{
	ll res1 = 0, res2 = 0;
	if(l > 1) res1 = fwget(fw2, l - 1) * l - fwget(fw1, l - 1);
	res2 = fwget(fw2, r) * (r + 1) - fwget(fw1, r);
	return res2 - res1;
}
int main()
{
	int n, m;
	ll ans = 0;
	scanf("%d%d", &n, &m);
	scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
	s1[n + 1] = s2[n + 1] = '@', s3[m + 1] = s4[m + 1] = '#';
	for(int i = 1; i <= m; i++) s4[m + 1 - i] = s3[i];
	for(int i = 1, j = n; i < j; i++, j--) swap(s2[i], s2[j]);
	calcz(m, m, s3, z3, s3, z3), calcz(m, m, s4, z4, s4, z4);
	calcz(m, n, s3, z3, s1, z1), calcz(m, n, s4, z4, s2, z2);
	for(int i = 1, j = n; i < j; i++, j--) swap(z2[i], z2[j]);
	for(int i = 1; i <= n; i++)
	{
		modify(m, 1, z1[i], 1);
		if(i >= m) modify(m, 1, z1[i - m + 1], -1);
		ans += get(m, m - z2[i], m - 1);
	}
	printf("%lld", ans);
	return 0;
}