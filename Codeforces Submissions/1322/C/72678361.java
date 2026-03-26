import java.io.*;
import java.util.*;
import java.util.Map.Entry;


public class  gym{
	static long gcd(long a, long b) {

		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
	static class set implements Comparable<set>{
		int[]nodes;
		set(TreeSet<Integer>t){
			nodes=new int[t.size()];
			int idx=0;
			for(int n:t) {
				nodes[idx++]=n;
			}
		}
		@Override
		public int compareTo(set o) {
			int idx=0;
			while(true) {
				if(idx>=nodes.length && idx>=o.nodes.length)return 0;
				if(idx>=nodes.length)return -1;
				if(idx>=o.nodes.length)return 1;
				
				if(nodes[idx]<o.nodes[idx])return -1;
				if(nodes[idx]>o.nodes[idx])return 1;
				idx++;
			}
		}
		
	}
	
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int tc=sc.nextInt();
		while(tc-->0) {
			int n=sc.nextInt(),m=sc.nextInt();
			long[]vals=sc.takearrl(n);
			TreeSet<Integer>[]adj=new TreeSet[n];
			for(int i=0;i<n;i++) {
				adj[i]=new TreeSet<Integer>();
			}
			for(int i=0;i<m;i++) {
				int left=sc.nextInt()-1,right=sc.nextInt()-1;
				adj[right].add(left);
			}
			TreeMap<set,Long>map=new TreeMap<set, Long>();
			for(int i=0;i<n;i++) {
				if(adj[i].size()==0)continue;
				set Set=new set(adj[i]);
				map.put(Set, map.getOrDefault(Set, 0l)+vals[i]);
			}
			long ans=0;
			for(Entry<set, Long>e:map.entrySet()) {
				ans=gcd(ans, e.getValue());
			}
			pw.println(ans);
			
		}
		pw.flush();
	}
	static class MScanner {
		StringTokenizer st;
		BufferedReader br;
		public MScanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}
 
		public MScanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int[] takearr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public long[] takearrl(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public Integer[] takearrobj(int n) throws IOException {
	        Integer[]in=new Integer[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public Long[] takearrlobj(int n) throws IOException {
	        Long[]in=new Long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
 
		public char nextChar() throws IOException {
			return next().charAt(0);
		}
 
		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}