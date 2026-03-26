import java.io.*;
import java.util.*;


public class  Main{
	static class node implements Comparable<node>{
		int i,val;
		node(int ii,int v){
			i=ii;val=v;
		}
		@Override
		public int compareTo(node o) {
			if(val==o.val)return i-o.i;
			return val-o.val;
		}
		public String toString() {return i+" "+val;}
	}
	static LinkedList<Integer>children[];
	static int[]cnt;
	static boolean ok=true;
	static int[]empty=new int[1];
	static ArrayList<node> dfs(int i) {
		if(!ok) {
			return new ArrayList<node>();
		}
		if(children[i].size()==0) {
			if(cnt[i]>0) {
				ok=false;
				return new ArrayList<node>();
			}
			ArrayList<node>arr=new ArrayList<Main.node>();
			arr.add(new node(i, 1));
			return arr;
		}
		ArrayList<node>arr=new ArrayList<Main.node>();
		for(int j:children[i]) {
			ArrayList<node>child=dfs(j);
			for(node n:child) {
				arr.add(n);
			}
		}
		if(cnt[i]>arr.size()) {
			ok=false;
			return new ArrayList<node>();
		}
		Collections.sort(arr);
		//System.out.println(i+" "+arr);
		int val;
		if(cnt[i]==0)val=1;
		else {
			val=arr.get(cnt[i]-1).val+1;
		}
		if(cnt[i]<arr.size() && arr.get(cnt[i]).val<=val) {
			int dif=val-arr.get(cnt[i]).val+1;
			for(int idx=cnt[i];idx<arr.size();idx++) {
					node cur=arr.get(idx);
					arr.set(idx, new node(cur.i, cur.val+dif));
			}
		}
		arr.add(new node(i, val));
		return arr;
	}
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt();
		children=new LinkedList[n];
		cnt=new int[n];
		int root=-1;
		for(int i=0;i<n;i++)children[i]=new LinkedList<Integer>();
		for(int i=0;i<n;i++) {
			int par=sc.nextInt()-1;cnt[i]=sc.nextInt();
			if(par!=-1) {
				children[par].add(i);
			}
			else {
				root=i;
			}
		}
		ArrayList<node>ans=dfs(root);
		//System.out.println(ans);
		if(!ok) {
			pw.println("NO");
			pw.flush();
			return;
		}
		pw.println("YES");
		int[]vals=new int[n];
		for(node x:ans) {
			vals[x.i]=x.val;
		}
		for(int i:vals)pw.println(i);
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