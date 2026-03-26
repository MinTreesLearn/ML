/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
    static List<Integer> al[];
    static int par[];
    static int dist[];
    static boolean vis[];
    static int n;
    
    static int bfs(int u) {
        Queue<Integer> q=new LinkedList<>();
        q.add(u);
        
        par[u]=0;
        vis[u]=true;
        dist[u]=0;
        
        while(!q.isEmpty()){
            int cur=q.poll();
          //  System.out.println(cur);
            for(int e:al[cur]){
                if(!vis[e]) {
                    vis[e]=true;
                    dist[e]=dist[cur]+1;
                    par[e]=cur;
                    q.add(e);
                }
            }
        }
        // for(int e:dist)
        // System.out.print(e+" ");
        // System.out.println();
        
        int max=0;
        for(int i=1;i<=n;i++) {
            if(dist[i]>dist[max]) max=i;
        }
        return max;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		PrintWriter out=new PrintWriter(System.out);
		 n=sc.nextInt();
		al=new ArrayList[n+1];
		for(int i=0;i<=n;i++) al[i]=new ArrayList<>();
		
		for(int i=0;i<n-1;i++) {
		    int u=sc.nextInt();
		    int v=sc.nextInt();
		    al[u].add(v);
		    al[v].add(u);
		}
		dist=new int[n+1];
		par=new int[n+1];
		vis=new boolean[n+1];
		int firstNode=bfs(1);
		
			dist=new int[n+1];
		par=new int[n+1];
		vis=new boolean[n+1];
		int secondNode=bfs(firstNode);
		
	//	System.out.println(firstNode+" "+secondNode);
	   int ans=dist[secondNode];
	   if(ans==n-1){
	   out.println(ans);
	   out.println(secondNode+" "+par[secondNode]+" "+firstNode);
	   }
	   else {
	       int temp=secondNode;
	        Queue<Integer> q=new LinkedList<>();
	        boolean vis[]=new boolean[n+1];
	        while(secondNode!=firstNode){
	             q.add(secondNode);
	             vis[secondNode]=true;
	            secondNode=par[secondNode];
	        }
	        q.add(firstNode);
	        vis[firstNode]=true;
	        
	        int dist[]=new int[n+1];
	        while(!q.isEmpty()) {
	            int cur=q.poll();
	            for(int e:al[cur]){
                if(!vis[e]) {
                    vis[e]=true;
                    dist[e]=dist[cur]+1;
                    q.add(e);
                }
            }
	        }
	         int max=0;
        for(int i=1;i<=n;i++) {
            if(dist[i]>dist[max]) max=i;
        }
        
        out.println(ans+dist[max]);
	   out.println(temp+" "+max+" "+firstNode);
	        
	   }
		out.flush();
		out.close();
	}
}
