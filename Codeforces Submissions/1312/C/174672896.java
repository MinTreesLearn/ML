import java.io.*;

import java.util.*;
 public class zia
 { 
	static boolean prime[] = new boolean[25001];
static void shuffleArray(long[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            long tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }   
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
	public static long lcm(long a,long b)
	{
		long max=Math.max(a, b);
		long min=Math.min(a, b);
		for(int i=1;;i++)
		{
			if((max*i)%min==0)
			return max;
		}
	}
	public static long calculate(long a,long b,long x,long y,long n)
	{
		if(a-x>=n)
		{
			a-=n;
		}
		else 
		{
			b=b-(n-(a-x));
			a=x;
			if(b<y)
			b=y;

		}
		return a*b;
	}
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
	public static int lowerbound(int s,int e, long ar[],long x)
	{
		int res=-1;
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
	public static int log2(int a)
	{ double d=Math.log(a)/Math.log(2);
		return (int)d+1;

	}
	public static int log10(long a)
	{ double d=Math.log(a)/Math.log(10);
		return (int)d;

	}
	public static int find(int ar[],int x)
	{
		int count=0;
		for(int i=0;i<ar.length;i+=2)
		{
			if((ar[i]&1)!=x)
			count++;
		}
		return count;
	}
	public static void main(String[] args) throws Exception
  {
		FastIO sc = new FastIO();
		
 
		//sc.println();
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx CODE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
		int test=sc.nextInt();
		
		// // double c=Math.log(10);
		// boolean prime[]=new boolean[1000001];
		// sieve(1000000, prime);
		while(test-->0)
		{
			


			int n=sc.nextInt();
			long k=sc.nextLong();
			long ar[]=new long[n];
			long max=0;
			for(int i=0;i<n;i++)
			 {
				ar[i]=sc.nextLong();
				if(ar[i]>max)
				max=ar[i];
			 }
			//  long maxPower=(long)(Math.ceil(((double)Math.log(max))/Math.log(k)));
			long maxPower=(long)Math.ceil(16.0/Math.log10(k));
			// sc.println(maxPower+" "+k);
			 long maxK=powerwithoutmod(k,maxPower);
			 while(maxK!=0)
			 {
				// sc.println(maxK);
				for(int i=0;i<n;i++)
				{
					if(ar[i]>=maxK)
					{ar[i]=ar[i]-maxK;break;}
				}
				maxK=maxK/k;

			 }
			 String res="YES";
			 for(int i=0;i<n;i++)
			{
				if(ar[i]>0)
				{res="NO";break;}
			}
			sc.println(res);
			
			  


			
			
			
			

			
		
		
				
			
		





		}
				
	
	   
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx CODE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
sc.close();	
}	
}


class pair implements Comparable<pair>{
	char value;
	int frequency;
	pair(char value,int frequency)
	{this.value=value;
		this.frequency=frequency;

	}
	public int compareTo(pair p)
	{return -this.frequency+p.frequency;}
}
class triplet implements Comparable<triplet>{
	int first,second,third;
	triplet(int first,int second,int third)
	{this.first=first;
		this.second=second;
		this.third=third;

	}
	public int compareTo(triplet p)
	{return this.third-p.third;}
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
