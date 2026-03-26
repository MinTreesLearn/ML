import java.io.*;
import java.util.*;

public class Codeforces
{
    public static void main(String args[])throws Exception
    {
        BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        String s[]=bu.readLine().split(" ");
        int n=Integer.parseInt(s[0]),k=Integer.parseInt(s[1]);
        int i,sz[]=new int[n];
        ArrayList<Road> g[]=new ArrayList[n];
        for(i=0;i<n;i++) g[i]=new ArrayList<>();
        for(i=0;i<n-1;i++)
        {
            s=bu.readLine().split(" ");
            int u=Integer.parseInt(s[0])-1,v=Integer.parseInt(s[1])-1;
            g[u].add(new Road(v,i));
            g[v].add(new Road(u,i));
            sz[u]++; sz[v]++;
        }

        int l=1,r=n-1,ans=r,mid,f[]=new int[n];
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(possible(sz,mid,k))
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        fill(g,f,ans);
        sb.append(ans+"\n");
        for(i=0;i<n-1;i++) sb.append(f[i]+1+" ");
        sb.append("\n");
        System.out.print(sb);
    }

    static boolean possible(int g[],int m,int k)
    {
        int i,n=g.length,y=0;
        for(i=0;i<n;i++)
        {
            if(g[i]>m) y++;
            if(y>k) return false;
        }
        return true;
    }

    static void fill(ArrayList<Road> g[],int f[],int m)
    {
        Queue<Integer> q=new LinkedList<>();
        boolean v[]=new boolean[f.length];
        v[0]=true;
        int col=0,y=0,c[]=new int[f.length];
        for(Road x:g[0])
        {
            q.add(x.v);
            f[x.i]=col;
            v[x.v]=true;
            c[x.v]=col;
            col++; col%=m;
        }

        while(!q.isEmpty())
        {
            int p=q.poll();
            col=c[p];
            col++; col%=m;
            for(Road x:g[p])
            if(!v[x.v])
            {
                q.add(x.v);
                v[x.v]=true;
                c[x.v]=col;
                f[x.i]=col;
                col++; col%=m;
            }
        }
    }

    static class Road
    {
        int v,i;
        Road(int a,int b)
        {
            v=a;
            i=b;
        }
    }
}