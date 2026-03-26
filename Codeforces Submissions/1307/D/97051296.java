import java.util.*;
import java.io.*;
public class Main
{
    static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
    static class Pair implements Comparable<Pair>
    {
        int f,s;
        Pair(int f,int s)
        {
            this.f=f;
            this.s=s;
        }
        
        public int compareTo(Pair p)
        {
            return this.s-p.s;
        }
    }
    static ArrayList<Integer> edge[];
    public static void main(String args[])throws Exception
    {
        FastReader fs=new FastReader();
        PrintWriter pw=new PrintWriter(System.out);
        int n=fs.nextInt();
        int m=fs.nextInt();
        int k=fs.nextInt();
        int arr[]=new int[k];
        boolean s[]=new boolean[n+1];
        for(int i=0;i<k;i++)
        {
            arr[i]=fs.nextInt();
            s[arr[i]]=true;
        }
        edge=new ArrayList[n+1];
        for(int i=1;i<=n;i++)
        edge[i]=new ArrayList<>();
        for(int i=0;i<m;i++)
        {
            int u=fs.nextInt();
            int v=fs.nextInt();
            edge[u].add(v);
            edge[v].add(u);            
        }
        int [] d1=new int[n+1],dn=new int[n+1];
        Queue<Integer> queue=new LinkedList<>();
        boolean pres=false;
        boolean vis[]=new boolean[n+1];
        vis[1]=true;
        queue.add(1);
        ArrayList<Pair> p=new ArrayList<>();
        if(s[1])p.add(new Pair(0,1));
        while(!queue.isEmpty())
        {
            int node=queue.poll();
            for(int v:edge[node])
            {
                if(s[v]&&s[node])pres=true;
                if(!vis[v])
                {
                    d1[v]=d1[node]+1;
                    vis[v]=true;
                    queue.add(v);
                    if(s[v])p.add(new Pair(d1[v],v));
                }
            }
        }
        if(pres)
        {
            System.out.println(d1[n]);
            return;
        }
        Arrays.fill(vis,false);
        vis[n]=true;
        queue.add(n);
        while(!queue.isEmpty())
        {
            int node=queue.poll();
            for(int v:edge[node])
            {
                if(!vis[v])
                {
                    dn[v]=dn[node]+1;
                    vis[v]=true;
                    queue.add(v);
                }
            }
        }
        int ans=0,curr=dn[p.get(k-1).s];
        for(int i=k-2;i>=0;i--)
        {
            ans=Math.max(ans,d1[p.get(i).s]+curr+1);
            curr=Math.max(curr,dn[p.get(i).s]);
        }
        ans=Math.min(ans,d1[n]);
        pw.println(ans);
        pw.flush();
        pw.close();
    }
}