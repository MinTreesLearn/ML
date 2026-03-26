import java.io.*;
import java.nio.file.FileStore;
import java.util.*;
 public class zia
 {  
	static boolean prime[] = new boolean[25001];
	static void ruffleSort(int[] a) {
        int n=a.length;
		Random random = new Random();
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n), temp=a[oi];
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
	public static double log2(long a)
	{ double d=Math.log(a)/Math.log(2);
		return d;

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
	public static int gcd(int a, int b)
    {
        if (a == 0)
            return b;
 
        return gcd(b % a, a);
    }
	public static long frogK(int index,long height[],long output[],int k)
	{
		if(index==1) 
		return 0;
		
		if(output[index]==0)
		{
			long MinEnergy=Long.MAX_VALUE;
			for(int j=1;j<=k&&index-j>=1;j++)
			 MinEnergy=Math.min(MinEnergy,frogK(index-j, height, output, k)+Math.abs(height[index]-height[index-j]));
			output[index]=MinEnergy;
		}
		return output[index];
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
	public static void solve(int s,int m,ArrayList<Integer> digits)
	{
		
		for(int i=0;i<m;i++)
		{
			if(s>=9)
			{
				digits.add(9);
				s-=9;
			}
			else 
			{
				if(s!=0)
				{digits.add(s);s=0;}
				else
				digits.add(0);
			}
		}
		

	}
	public static boolean isValid(int hour,int minute,int h,int m)
	{
		int ar[]={0,1,5,-1,-1,2,-1,-1,8,-1};
		if(ar[minute%10]==-1||ar[minute/10]==-1 ||ar[hour%10]==-1||ar[hour/10]==-1)
		   return false;
		int mirrorHour=ar[minute%10]*10+ar[minute/10];
		int mirrorMinute=ar[hour%10]*10+ar[hour/10];
		if(mirrorMinute>=m||mirrorHour>=h)
		return false;

		return true;

	}
	public static void main(String[] args) throws Exception
   {
		FastIO sc = new FastIO();
		
 
		//sc.println();
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx CODE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
		int test=sc.nextInt();
		
		// // double c=Math.log(10);
		// boolean prime[]=new boolean[1000000001];
		// sieve(1000000000, prime);
		while(test-->0)
		{



			
			char ar[]=sc.next().toCharArray();
			int n=ar.length;
			int res=1,jump=1;
			for(int i=0;i<n;i++)
			{
				if(ar[i]=='L')
				{
					jump++;
					res=Math.max(res,jump);
				}
				else
				jump=1;
			}
			sc.println(res);
			
		

		

		  


		
		


	
			
			
		



			  


			
			
			
			

			
		
		
				
			
		





		}
				
	
	   
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx CODE xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
sc.close();	
}	
}


class pair implements Comparable<pair>{
	long a;
	long b;
	pair(long a,long b)
	{this.a=a;
		this.b=b;

	}
	public int compareTo(pair p)
	{return (int)(-this.a+p.a);}
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
