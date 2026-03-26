// LUOGU_RID: 97884369
# include <bits/stdc++.h>
using namespace std;
int n,m,K,w[200010],f[200010][300],g[300],tn[300][300];
pair<int,int> ok[100010];
vector<int> op[200010];
vector<pair<int,int> > kl;
int main() {
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);

    scanf("%d%d%d",&n,&m,&K);
    for (int i=1;i<=n;i++) scanf("%d%d",&ok[i].first,&ok[i].second);

    for (int i=0;i<1<<K;i++) for (int j=0;j<1<<K;j++) for (int k=0,cnt=0;k<K;k++) if (j&(1<<k)) tn[i][j]|=((i>>k)&1)<<cnt, cnt++;

    vector<int> lsh;
    for (int i=1;i<=n;i++) lsh.push_back(ok[i].first), lsh.push_back(ok[i].second+1);
    sort(lsh.begin(),lsh.end()), lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
    for (int i=1;i<=n;i++) ok[i].first=lower_bound(lsh.begin(),lsh.end(),ok[i].first)-lsh.begin()+1, ok[i].second=lower_bound(lsh.begin(),lsh.end(),ok[i].second+1)-lsh.begin();

    m=lsh.size();
    for (int i=1;i<=m;i++) w[i]=lsh[i]-lsh[i-1];

    for (int i=1;i<=n;i++) op[ok[i].first].push_back(ok[i].second);

    for (int i=1;i<=m;i++) {
        int cnt=kl.size();
        for (auto o : op[i]) kl.push_back(pair<int,int> (i,o));
        for (int j=0;j<1<<(int)kl.size();j++) f[i][j]=max(f[i][j],f[i-1][j&((1<<cnt)-1)]+__builtin_popcount(j)%2*w[i]);

        int oi=0;
        vector<pair<int,int> > kk;
        for (int j=0;j<(int)kl.size();j++) if (kl[j].second>i) oi|=1<<j, kk.push_back(kl[j]);
        for (int j=0;j<1<<(int)kl.size();j++) g[tn[j][oi]]=max(g[tn[j][oi]],f[i][j]);
        kl=kk, memcpy(f[i],g,sizeof(g)), memset(g,0,sizeof(g));
    }

    printf("%d\n",f[m][0]);

    return 0;
}