import java.io.*;

import java.util.*;

/*


*/

 
 public class A {
	static FastReader sc=null;
	
 
	public static void main(String[] args) {
		sc=new FastReader();
		int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
		int a[]=sc.readArray(k);
		for(int i=0;i<k;i++)a[i]--;
		ArrayList<Integer> adj[]=new ArrayList[n];
		for(int i=0;i<n;i++)adj[i]=new ArrayList<>();
		
		
		for(int i=0;i<m;i++) {
			int v=sc.nextInt()-1,w=sc.nextInt()-1;
			adj[v].add(w);
			adj[w].add(v);
		}
		int dists[]=bfs(adj,0),diste[]=bfs(adj,n-1);
		//print(dists);
		//print(diste);
		
		//maximize the minimum of (dist_s[u]+dist_e[v],dist_e[u]+dist_s[v])
		//we have to choose a combination such that this distance is minimized
		Pair ps[]=new Pair[k];
		for(int i=0;i<k;i++) {
			ps[i]=new Pair(a[i],dists[a[i]],diste[a[i]]);
		}
		Arrays.sort(ps);
		//gives the maximum end until now
		int suff[]=new int[k];
		suff[k-1]=ps[k-1].e;
		for(int i=k-2;i>=0;i--)suff[i]=Math.max(suff[i+1], ps[i].e);
		int ans=0;
		for(int i=0;i+1<k;i++) {
			ans=Math.max(ps[i].s+suff[i+1]+1, ans);
		}
		
//		int max=0;
//		for(int i=0;i<k;i++) {
//			for(int j=i+1;j<k;j++) {
//				int d=Math.min(dists[a[i]]+diste[a[j]]+1, dists[a[j]]+diste[a[i]]+1);
//				max=Math.max(d,max);
//			}
//		}
//		System.out.println(max);
		
		ans=(Math.min(ans, dists[n-1]));
		System.out.println(ans);
		
		
		
		
		
	}
	static class Pair implements Comparable<Pair>{
		int id,s,e;
		Pair(int id,int s,int e){
			this.id=id;
			this.s=s;
			this.e=e;
		}
		public int compareTo(Pair o) {
			return this.s-o.s;
		}
		
	}
	static int[] bfs(ArrayList<Integer> adj[],int src) {
		int n=adj.length;
		int dist[]=new int[n];
		Arrays.fill(dist, -1);
		
		dist[src]=0;
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		bfs.add(src);
		while(!bfs.isEmpty()) {
			int q=bfs.remove();
			for(int e:adj[q]) {
				if(dist[e]==-1) {
					dist[e]=dist[q]+1;
					bfs.add(e);
				}
			}
		}
		
		return dist;
	}
	
	static int[] ruffleSort(int a[]) {
		ArrayList<Integer> al=new ArrayList<>();
		for(int i:a)al.add(i);
		Collections.sort(al);
		for(int i=0;i<a.length;i++)a[i]=al.get(i);
		return a;
	}
	
	static void print(int a[]) {
		for(int e:a) {
			System.out.print(e+" ");
		}
		System.out.println();
	}
	
	static class FastReader{
		
		StringTokenizer st=new StringTokenizer("");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		String next() {
			while(!st.hasMoreTokens()) 
				try {
					st=new StringTokenizer(br.readLine());
				}
			   catch(IOException e){
				   e.printStackTrace();
			   }
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		int[] readArray(int n) {
			int a[]=new int[n];
			for(int i=0;i<n;i++)a[i]=sc.nextInt();
			return a;
		}
	}
	
	
}
