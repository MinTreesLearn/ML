#include <bits/stdc++.h>
using namespace std;
#define int long long



struct segtree
{
    vector<int> v;
    vector<int> ops;

    void init(int n)
    {
        int curr=1;
        while(curr<n){curr=curr*2;}
        for(int i=0;i<2*curr;i++)
            {
                v.push_back(0);
                ops.push_back(0);

            }
    }





    void update(int lx,int rx,int curr,int l,int r,int z)
    {
        //Add z from l to r
        if(lx>=l && rx<=r){v[curr]+=z;ops[curr]+=z;return;}
        if(lx>=r || l>=rx){return ;}
        int m=(lx+rx)/2;
        update(lx,m,2*curr+1,l,r,z);
        update(m,rx,2*curr+2,l,r,z);
        v[curr]=max(v[2*curr+1],v[2*curr+2])+ops[curr];
    }

    int getans(int lx,int rx,int curr,int l,int r)
    {
        if(lx>=l && rx<=r){return v[curr];}
        if(l>=rx || lx>=r){return -1e12;}

        int m=(lx+rx)/2;
        auto a=max(getans(lx,m,2*curr+1,l,r),getans(m,rx,2*curr+2,l,r));
        return a+ops[curr];
    }
};






int32_t main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);


   int n,m,p;
   cin>>n>>m>>p;

   pair<int,int> a[n];
   for(int i=0;i<n;i++){cin>>a[i].first>>a[i].second;}

   sort(a,a+n);

   pair<int,int> b[m];
   for(int i=0;i<m;i++){cin>>b[i].first>>b[i].second;}

   sort(b,b+m);

   tuple<int,int,int> c[p];
   for(int i=0;i<p;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        c[i]={x,y,z};
    }

    sort(c,c+p);

    struct segtree st;
    st.init(m);


    for(int i=0;i<m;i++)
        {
            st.update(0,m,0,i,i+1,-b[i].second);
        }

    int curr=0;
    int ans=-1e18;
    for(int i=0;i<n;i++)
        {
            while(curr<p && (get<0>)(c[curr])<a[i].first)
                {
                    int x=(get<0>)(c[curr]);
                    int y=(get<1>)(c[curr]);
                    int z=(get<2>)(c[curr]);

                    int ax=lower_bound(b,b+m,make_pair(y+1,(int)(-1)))-b;
                    st.update(0,m,0,ax,m,z);
                    curr++;
                }
            ans=max(ans,st.getans(0,m,0,0,m)-a[i].second);
        }
    cout<<ans;
}
