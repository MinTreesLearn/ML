import java.io.*;
import java.nio.file.FileStore;
import java.util.*;
 public class zia
 {  
	
 
	static void BFS(ArrayList<ArrayList<Integer>> adj,int s, boolean[] visited) 
	{ 
    	Queue<Integer> q=new LinkedList<>();
    	
    	visited[s] = true; 
    	q.add(s); 
    
    	while(q.isEmpty()==false) 
    	{ 
    		int u = q.poll(); 
    		 
    		for(int v:adj.get(u)){
    		    if(visited[v]==false){
    		        visited[v]=true;
    		        q.add(v);
    		    }
    		} 
    	} 
	} 
	// static int BFS(ArrayList<ArrayList<Integer>> adj,pair s, boolean[] visited,int ar[],int m) 
	// { 
    // 	Queue<pair> q=new LinkedList<>();
    	
    // 	visited[s.a] = true; 
    // 	q.add(s); 
    
	// 	int count=0;
    // 	while(q.isEmpty()==false) 
    // 	{ 
    // 		pair u = q.poll(); 
	// 		// if(adj.get(u.a).size()==0)
	// 		// count++;
	 
	// 		boolean end=true;
    // 		for(int v:adj.get(u.a)){
    // 		    if(visited[v]==false){
    // 		        visited[v]=true;
	// 				end=false;
	// 				int cat=ar[v]==0?0:ar[v]+u.b;
	// 				if(cat>m)
	// 				continue;
    // 		        q.add(new pair(v, cat));
	// 				// System.out.print("--"+v+" "+cat+"--");
    // 		    }
    // 		} 
	// 		if(end)
	// 		count++;
	// 		// System.out.println(u.a+" "+adj.get(u.a).size()+" count "+count);
    // 	} 
	// 	return count;
	// } 
	static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) 
	{ 
		adj.get(u).add(v); 
		adj.get(v).add(u); 
	} 
	static void ruffleSort(long[] a) {
        int n=a.length;
		Random random = new Random();
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n);
			long temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
	static void ruffleSort(int[] a) {
        int n=a.length;
		Random random = new Random();
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n);
			int temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
	public static int Lcm(int a,int b)
	{ int max=Math.max(a,b);
		for(int i=1;;i++)
		{
			if((max*i)%a==0&&(max*i)%b==0)
			return (max*i);
		}
 
	}
  static void sieve(int n,boolean prime[])
    {
       
        // boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;
 
        for (int p = 2; p * p <= n; p++) {
            
            if (prime[p] == true) {
               
                for (int i = p * p; i <= n; i =i+ p)
                    prime[i] = false;
            }
        }
 
        
    }
 
	// public static String run(int ar[],int n)
	// { 
			
	// }
	
	
	public static int upperbound(int s,int e, long ar[],long x)
	{
		int res=-1;
		while(s<=e)
		{ int mid=((s-e)/2)+e;
			if(ar[mid]>x)	
			{e=mid-1;res=mid;}
			else if(ar[mid]<x)
			{s=mid+1;}
			else
			{e=mid-1;res=mid;
			 if(mid>0&&ar[mid]==ar[mid-1])
			 e=mid-1;
			 else
			 break;
			}
 
		}
		return res;
	}
	public static long lowerbound(int s,int e, long ar[],long x)
	{
		long res=-1;
		while(s<=e)
		{ int mid=((s-e)/2)+e;
			if(ar[mid]>x)	
			{e=mid-1;}
			else if(ar[mid]<x)
			{s=mid+1;res=mid;}
			else
			{res=mid;
				if(mid+1<ar.length&&ar[mid]==ar[mid+1])
			    s=mid+1;
			    else
				break;}
 
		}
		return res;
	}
	
	static long modulo=1000000007;
	public static long power(long a, long b)
	{
		if(b==0) return 1;
		long temp=power(a,b/2)%modulo;
		
		if((b&1)==0)
		return (temp*temp)%modulo;
		else 
		return (((temp*temp)%modulo)*a)%modulo;
	}
	public static long powerwithoutmod(long a, long b)
	{
		if(b==0) return 1;
		long temp=power(a,b/2);
		
		if((b&1)==0)
		return (temp*temp);
		else 
		return ((temp*temp)*a);
	}
	public static double log2(long a)
	{ double d=Math.log(a)/Math.log(2);
		return d;
 
	}
	public static int log10(long a)
	{ double d=Math.log(a)/Math.log(10);
		return (int)d;
 
	}
	
	public static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
 
        return gcd(b % a, a);
    }
	
	public static void tree(int s,int e,int ar[],int c)
	{
	  if(s<=e)
	  {
		  int max=s;
		  for(int i=s;i<=e;i++)
		   if(ar[i]>ar[max])
			 max=i;
			 
		  ar[max]=c++;
		  tree(s,max-1,ar,c);
		  tree(max+1,e,ar,c);
	  }
	}
	
 static int resturant=0;
 static void DFS(ArrayList<ArrayList<Integer>> al,boolean visited[],int s,int max,int curr,int ar[])
 {
	
	visited[s]=true;
	if(al.get(s).size()==1&&visited[al.get(s).get(0)]==true)
	{resturant++;return;}
	// System.out.println(s+" "+curr);
	for(int x:al.get(s))
	{
		if(visited[x]==false)
		{
			if(ar[x]==0)
			DFS(al, visited, x, max, 0, ar);
			else if(curr+ar[x]<=max)
			DFS(al, visited, x, max, curr+ar[x], ar);
			
		}
	}
	
 }
	
	public static void main(String[] args) throws Exception
   {
		FastIO sc = new FastIO();
		
 
		//sc.println();
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx CODE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
		int test=sc.nextInt();
		
		// // double c=Math.log(10);
		// boolean prime[]=new boolean[233334];
		// sieve(233334, prime);
		// HashMap<Character,Integer> hm=new HashMap<>(9);
		// char c='1';
		// for(int i=1;i<=9;i++)
		//  hm.put(c++,i);
 
		
 
		while(test-->0)
		{
		
		
			int n=sc.nextInt();
			int ar[]=new int[n];
			for (int i = 0; i < n; i++) {
				ar[i]=sc.nextInt();
			}
			int d=0;
			int max=Integer.MIN_VALUE,min=Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				if(ar[i]==-1)
				{
					if(i-1>=0&&ar[i-1]!=-1)
					{
						min=Math.min(min,ar[i-1]);
				        max=Math.max(max,ar[i-1]);
					}
					if(i+1<n&&ar[i+1]!=-1)
					{
						min=Math.min(min,ar[i+1]);
				        max=Math.max(max,ar[i+1]);
					}
				}
				else
				{
					if(i-1>=0&&ar[i-1]!=-1)
					d=Math.max(d,Math.abs(ar[i-1]-ar[i]));
					if(i+1<n&&ar[i+1]!=-1)
					d=Math.max(d,Math.abs(ar[i+1]-ar[i]));
				}
			}
			if(min==Integer.MAX_VALUE&&max==Integer.MIN_VALUE)
			{
				sc.println("0 0");
			}
			else if(min==max)
			{
				sc.println(d+" "+min);
			}
			else
			{
			int mean=(min+max)/2;
			d=Math.max(d,mean-min);
			d=Math.max(d,max-mean);
			sc.println(d+" "+mean);
			}
			
			
			

		
		   
		 



		
		
		
 
 
 
 
		}
				
	
	   
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx CODE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
sc.close();	
}	
}
 
 
class pair implements Comparable<pair>{
	int a;
	int b;
	pair(int a,int b)
	{this.a=a;
		this.b=b;
 
	}
	public int compareTo(pair p)
	{
		if(this.a-p.a==0)
		return this.b-p.b;

		return (this.a-p.a);
	}
}
class triplet implements Comparable<triplet>{
	long first,second,third;
	triplet(long first,long second,long third)
	{this.first=first;
		this.second=second;
		this.third=third;
 
	}
	public int compareTo(triplet p)
	{ 
		return (int)(this.first-p.first);
	}
}
// class triplet
// {
// 	int x1,x2,i;
// 	triplet(int a,int b,int c)
// 	{x1=a;x2=b;i=c;}
// }
 class FastIO extends PrintWriter {
	private InputStream stream;
	private byte[] buf = new byte[1<<16];
	private int curChar, numChars;
 
	// standard input
	public FastIO() { this(System.in,System.out); }
	public FastIO(InputStream i, OutputStream o) {
		super(o);
		stream = i;
	}
	// file input
	public FastIO(String i, String o) throws IOException {
		super(new FileWriter(o));
		stream = new FileInputStream(i);
	}
 
	// throws InputMismatchException() if previously detected end of file
	private int nextByte() {
		if (numChars == -1) throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars == -1) return -1; // end of file
		}
		return buf[curChar++];
	}
 
	public String nextLine() {
		int c; do { c = nextByte(); } while (c <= '\n');
		StringBuilder res = new StringBuilder();
		do { res.appendCodePoint(c); c = nextByte(); } while (c > '\n');
		return res.toString();
	}
 
	public String next() {
		int c; do { c = nextByte(); } while (c <= ' ');
		StringBuilder res = new StringBuilder();
		do { res.appendCodePoint(c); c = nextByte(); } while (c > ' ');
		return res.toString();
	}
 
	public int nextInt() { 
		int c; do { c = nextByte(); } while (c <= ' ');
		int sgn = 1; if (c == '-') { sgn = -1; c = nextByte(); }
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res = 10*res+c-'0';
			c = nextByte();
		} while (c > ' ');
		return res * sgn;
	}
 
  public long nextLong() { 
		int c; do { c = nextByte(); } while (c <= ' ');
		long sgn = 1; if (c == '-') { sgn = -1; c = nextByte(); }
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res = 10*res+c-'0';
			c = nextByte();
		} while (c > ' ');
		return res * sgn;
	}
 
	public double nextDouble() { return Double.parseDouble(next()); }
}