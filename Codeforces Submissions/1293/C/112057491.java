//Implemented By Aman Kotiyal Date:-05-Apr-2021  Time:-1:24:45 pm
import java.io.*;
import java.util.*;

public class ques1
{
	public static void main(String[] args)throws Exception{ new ques1().run();} 
	long mod=1000000000+7;
	HashMap<String,HashSet<String>> map;
	int ar[][];
	void solve() throws Exception
	{
		int n=ni();
		int q=ni();
		ar=new int[4][n+3];
		map= new HashMap<>();
		for (int i = 0; i < q; i++)
		{
			int r=ni(); 
			int c=ni();
			ar[r][c]^=1;
			if(ar[r][c]==0)
			{
				if(map.containsKey(r+" "+c))
				{
					remove(r,c,r+1,c);
					remove(r,c,r+1,c+1);
					remove(r,c,r+1,c-1);
					
					remove(r,c,r-1,c);
					remove(r,c,r-1,c+1);
					remove(r,c,r-1,c-1);
				}
				
				if(map.size()==0)
					out.println("Yes");
				else
					out.println("No");
				continue;
			}
			
				add(r,c,r+1,c);
				add(r,c,r+1,c+1);
				add(r,c,r+1,c-1);
				
				add(r,c,r-1,c);
				add(r,c,r-1,c+1);
				add(r,c,r-1,c-1);
				
				if(map.size()==0)
					out.println("Yes");
				else
					out.println("No");
		}
	}
	void add(int a,int b,int c, int d)
	{
		if(ar[c][d]!=1)return;
		
		HashSet<String> tem=map.getOrDefault(a+" "+b, new HashSet<String>());
		tem.add(c+" "+d);
		map.put(a+" "+b ,tem);
		
		tem=map.getOrDefault(c+" "+d, new HashSet<String>());
		tem.add(a+" "+b);
		map.put(c+" "+d ,tem);
	}
	
	void remove(int a,int b,int c, int d)
	{
		if(!map.containsKey(a+" "+b))return;
		if(!map.get(a+" "+b).contains(c+" "+d))return;
		
		map.get(c+" "+d).remove(a+" "+b);
		if(map.get(c+" "+d).size()==0)
			map.remove(c+" "+d);
		
		map.get(a+" "+b).remove(c+" "+d);
		if(map.get(a+" "+b).size()==0)
			map.remove(a+" "+b);
	}
	/*FAST INPUT OUTPUT & METHODS BELOW*/
	
	private byte[] buf=new byte[1024];
	private int index;
	private InputStream in;
	private int total;
	private SpaceCharFilter filter;
	PrintWriter out;
	
	int min(int... ar){int min=Integer.MAX_VALUE;for(int i:ar)min=Math.min(min, i);return min;}
	long min(long... ar){long min=Long.MAX_VALUE;for(long i:ar)min=Math.min(min, i);return min;}
	int max(int... ar) {int max=Integer.MIN_VALUE;for(int i:ar)max=Math.max(max, i);return max;}
	long max(long... ar) {long max=Long.MIN_VALUE;for(long i:ar)max=Math.max(max, i);return max;}
	void reverse(int a[]){for(int i=0;i<a.length>>1;i++){int tem=a[i];a[i]=a[a.length-1-i];a[a.length-1-i]=tem;}}
	void reverse(long a[]){for(int i=0;i<a.length>>1;i++){long tem=a[i];a[i]=a[a.length-1-i];a[a.length-1-i]=tem;}}
	String reverse(String s){StringBuilder sb=new StringBuilder(s);sb.reverse();return sb.toString();}
	
	void shuffle(int a[]) {
		ArrayList<Integer> al = new ArrayList<>();
		for(int i=0;i<a.length;i++) 
			al.add(a[i]);
		
		Collections.sort(al);
		for(int i=0;i<a.length;i++) 
			a[i]=al.get(i);
	}
	long lcm(long a,long b)
	{
		return (a*b)/(gcd(a,b));
	}
	
	int gcd(int a, int b) 
	{ 
		if (a == 0) 
			return b; 
		return gcd(b%a, a); 
	} 
	long gcd(long a, long b) 
	{ 
		if (a == 0) 
			return b; 
		return gcd(b%a, a); 
	}
	/* for (1/a)%mod = ( a^(mod-2) )%mod  ----> use expo to calc -->(a^(mod-2)) */
	long expo(long p,long q)  /*  (p^q)%mod   */
	{
		long z = 1;
		while (q>0) {
			if (q%2 == 1) {
				z = (z * p)%mod;
			}
			p = (p*p)%mod;
			q >>= 1;
		}
		return z;
	}
	void run()throws Exception
	{
		in=System.in; out = new PrintWriter(System.out);
		solve();
		out.flush();
	}
	private int scan()throws IOException
	{
		if(total<0)
			throw new InputMismatchException();
		if(index>=total)
		{
			index=0;
			total=in.read(buf);
			if(total<=0)
				return -1;
		}
		return buf[index++];
	}
	private int ni() throws IOException 
	{
		int c = scan();
		while (isSpaceChar(c))
			c = scan();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = scan();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = scan();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
	private long nl() throws IOException 
	{
		long num = 0;
		int b;
		boolean minus = false;
		while ((b = scan()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = scan();
		}
		
		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = scan();
		}
	}
	private double nd() throws IOException{
		return Double.parseDouble(ns());
	}
	private String ns() throws IOException {
		int c = scan();
		while (isSpaceChar(c))
			c = scan();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = scan();
		} while (!isSpaceChar(c));
		return res.toString();
	}
	private String nss() throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		return br.readLine();
	}
	private char nc() throws IOException 
	{
		int c = scan();
		while (isSpaceChar(c))
			c = scan();
		return (char) c;
	}
	private boolean isWhiteSpace(int n)
	{
		if(n==' '||n=='\n'||n=='\r'||n=='\t'||n==-1)
			return true;
		return false;
	}
	private boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhiteSpace(c);
	}
	private interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}