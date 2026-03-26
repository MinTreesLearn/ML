import java.util.*;
import java.io.*;
 
public class Main {
	public static void main(String args[]) {new Main().run();}
 
	FastReader in = new FastReader();
	PrintWriter out = new PrintWriter(System.out);
	void run(){
		work();
		out.flush();
	}
	long mod=998244353;
	long gcd(long a,long b) {
		return a==0?b:gcd(b%a,a);
	}
	void work() {
		int n=ni();
		int[] A=nia(n);
		long[] W=na(n);
		long[] sum=new long[n];
		for(int i=0;i<n;i++) {
			sum[A[i]]=W[i];
		}
		for(int i=1;i<n;i++) {
			sum[i]+=sum[i-1];
		}
		Node root=new Node();
		for(int i=0;i<n;i++) {
			update(root,0,n-1,i,i,sum[i]);
		}
		long ret=Long.MAX_VALUE;
		long s=0;
		for(int i=0;i<n-1;i++) {
			int node=A[i];
			long w=W[i];
			s+=w;//前缀空集
			update(root,0,n-1,node,n-1,-w);
			if(node!=0)update(root,0,n-1,0,node-1,w);
			ret=Math.min(ret, root.min);
			ret=Math.min(ret, s);
		}
		out.println(ret);
	}
	
	void u2(Node node,long v) {
		node.min+=v;
		node.lazy+=v;
	}
	void updatelazy(Node node) {
		u2(getLnode(node),node.lazy);
		u2(getRnode(node),node.lazy);
		node.lazy=0;
	}
	private void update(Node node, int l, int r, int s,int e,long v) {
		if(l>=s&&r<=e) {
			node.min+=v;
			node.lazy+=v;
			return;
		}
		updatelazy(node);
		int m=l+(r-l)/2;
		if(m>=s) {
			update(getLnode(node),l,m,s,e,v);
		}
		if(m+1<=e) {
			update(getRnode(node),m+1,r,s,e,v);
		}
		node.min=Math.min(getLnode(node).min,getRnode(node).min);//左右节点可能有lazy标记
	}
 
	private Node getLnode(Node node) {
		if(node.lnode==null)node.lnode=new Node();
		return node.lnode;
	}
	private Node getRnode(Node node) {
		if(node.rnode==null)node.rnode=new Node();
		return node.rnode;
	}
	class Node{
		Node lnode,rnode;
		long lazy;
		long min;
	}
	
	//input
	private ArrayList<Integer>[] ng(int n, int m) {
		ArrayList<Integer>[] graph=(ArrayList<Integer>[])new ArrayList[n];
		for(int i=0;i<n;i++) {
			graph[i]=new ArrayList<>();
		}
		for(int i=1;i<=m;i++) {
			int s=in.nextInt()-1,e=in.nextInt()-1;
			graph[s].add(e);
			graph[e].add(s);
		}
		return graph;
	}
 
	private int ni() {
		return in.nextInt();
	}
 
	private long nl() {
		return in.nextLong();
	}
 
	private long[] na(int n) {
		long[] A=new long[n];
		for(int i=0;i<n;i++) {
			A[i]=in.nextLong();
		}
		return A;
	}
	private int[] nia(int n) {
		int[] A=new int[n];
		for(int i=0;i<n;i++) {
			A[i]=in.nextInt()-1;//
		}
		return A;
	}
}	
 
class FastReader
{
	BufferedReader br;
	StringTokenizer st;
 
	public FastReader()
	{
		br=new BufferedReader(new InputStreamReader(System.in));
	}
 
 
	public String next() 
	{
		while(st==null || !st.hasMoreElements())//回车，空行情况
		{
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}
 
	public int nextInt() 
	{
		return Integer.parseInt(next());
	}
 
	public long nextLong()
	{
		return Long.parseLong(next());
	}
}
	   		     					   				 		  			