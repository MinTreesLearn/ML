	import java.io.*;
	import java.lang.*;
	import java.util.*;
	
	
	public class ComdeFormces {	
		static int x[]= {0,-1,1,1,1,1,-1,-1};
		static int y[]= {-1,0,0,0,1,-1,1,-1};
//		static int dp[][][];
		static int seg[];
		static int E;
		static class Trie{
			Trie a[];
			int ind;
			public Trie() {
				this.a=new Trie[3];
				this.ind=-1;
			}
		}
		static long ncr[][];
		static int cst;
		static HashMap<Integer,Integer> hm;
		static int dp[][];
		static ArrayList<Integer> tp;
		public static void main(String[] args) throws Exception{
			// TODO Auto-generated method stub
		FastReader sc=new FastReader();
		BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
	//		 OutputStream out = new BufferedOutputStream ( System.out );
//	    int t=sc.nextInt();
		int tc=1;
		 
		 InverseofNumber(m);
	     InverseofFactorial(m);
	     factorial(m);
		 
        while(tc--!=0) {
        	 int n=sc.nextInt();
        	 int mm=sc.nextInt();
        	 if(n==2)log.write("0\n");
        	 else {
        	 long bn=Binomial(mm,n-1,m);
        	 bn=mul(bn,n-2);
        	 long tw=2;
        	 bn=mul(bn,pow(tw,(long)(n-3)));
        	 log.write(bn+"\n");
        	 }
        	 log.flush();

        	 
        }        
	        

	 
		}
		static int N = 1000001; 
		 
		// Array to store inverse of 1 to N
		static long[] factorialNumInverse = new long[N + 1];
		 
		// Array to precompute inverse of 1! to N!
		static long[] naturalNumInverse = new long[N + 1];
		 
		// Array to store factorial of first N numbers
		static long[] fact = new long[N + 1];
		 
		// Function to precompute inverse of numbers
		public static void InverseofNumber(int p)
		{
		    naturalNumInverse[0] = naturalNumInverse[1] = 1;
		     
		    for(int i = 2; i <= N; i++)
		        naturalNumInverse[i] = naturalNumInverse[p % i] *
		                                 (long)(p - p / i) % p;
		}
		 
		// Function to precompute inverse of factorials
		public static void InverseofFactorial(int p)
		{
		    factorialNumInverse[0] = factorialNumInverse[1] = 1;
		 
		    // Precompute inverse of natural numbers
		    for(int i = 2; i <= N; i++)
		        factorialNumInverse[i] = (naturalNumInverse[i] *
		                           factorialNumInverse[i - 1]) % p;
		}
		 
		// Function to calculate factorial of 1 to N
		public static void factorial(int p)
		{
		    fact[0] = 1;
		 
		    // Precompute factorials
		    for(int i = 1; i <= N; i++)
		    {
		        fact[i] = (fact[i - 1] * (long)i) % p;
		    }
		}
		 
		// Function to return nCr % p in O(1) time
		public static long Binomial(int N, int R, int p)
		{
		     
		    // n C r = n!*inverse(r!)*inverse((n-r)!)
		    long ans = ((fact[N] * factorialNumInverse[R]) %
		                       p * factorialNumInverse[N - R]) % p;
		     
		    return ans;
		}	
public static int m=(int)(998244353);	
public static int mul(int a, int b) {
	return ((a%m)*(b%m))%m;
}
public static long mul(long a, long b) {
	return ((a%m)*(b%m))%m;
}
public static int add(int a, int b) {
	return ((a%m)+(b%m))%m;
}
public static long add(long a, long b) {
	return ((a%m)+(b%m))%m;
}
public static long sub(long a,long b) {
return ((a%m)-(b%m)+m)%m;	
}
static long gcd(long a,long b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
static int gcd(int a,int b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
	static long ncr(int n, int r){
	    if(r>n-r)r=n-r;
	    long ans=1;
	    long m=(int)(1e9+7);
	    for(int i=0;i<r;i++){
	          ans=ans*(n-i);
	          ans/=i+1;
	    }
	    return ans;
	} 
public static class num{
	long v;
}
static long gcd(long a,long b,num x,num y) {
	if(b==0) {
		x.v=1;
		y.v=0;
		return a;
	}
	num x1=new num();
	num y1=new num();
	long ans=gcd(b,a%b,x1,y1);
	x.v=y1.v;
	y.v=x1.v-(a/b)*y1.v;
	return ans;
}	
static long inverse(long b,long m) {
	num x=new num();
	num y=new num();
	long gc=gcd(b,m,x,y);
	if(gc!=1) {
		return -1;
	}
	return (x.v%m+m)%m;
	
}
static long div(long a,long b,long m) {
	a%=m;
	if(inverse(b,m)==-1)return a/b;
	 return (inverse(b,m)*a)%m;
}	
public static class trip{
	int a;
	int b;
	long c;
	int d;
	public trip(int a,int b,long  c,int d) {
		this.a=a;
		this.b=b;
		this.c=c;
		this.d=d;
	}
}	
static void mergesort(int[] a,int start,int end) {
		if(start>=end)return ;
		int mid=start+(end-start)/2;
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
		
	}
static void merge(int[] a, int start,int mid,int end) {
		int ptr1=start;
		int ptr2=mid+1;
		int b[]=new int[end-start+1];
		int i=0;
		while(ptr1<=mid && ptr2<=end) {
			if(a[ptr1]<=a[ptr2]) {
				b[i]=a[ptr1];
				ptr1++;
				i++;
			}
			else {
				b[i]=a[ptr2];
				ptr2++;
				i++;
			}
		}
		while(ptr1<=mid) {
			b[i]=a[ptr1];
			ptr1++;
			i++;
		}
		while(ptr2<=end) {
			b[i]=a[ptr2];
			ptr2++;
			i++;
		}
		for(int j=start;j<=end;j++) {
			a[j]=b[j-start];
		}
	}
	public static class FastReader {
	
			BufferedReader b;
			StringTokenizer s;
			public FastReader() {
				b=new BufferedReader(new InputStreamReader(System.in));
			}
			String next() {
				while(s==null ||!s.hasMoreElements()) {
					try {
						s=new StringTokenizer(b.readLine());
					}
					catch(IOException e) {
						e.printStackTrace();
					}
				}
				return s.nextToken();
			}
			public int nextInt() {
				return Integer.parseInt(next());
			}
			public long nextLong() {
				return Long.parseLong(next());
			}
			public double nextDouble() {
				return Double.parseDouble(next());
			}
			String nextLine() {
				String str="";
				try {
					str=b.readLine();
				}
				catch(IOException e) {
					e.printStackTrace();
				}
				return str;
			}
			boolean hasNext() {
			    if (s != null && s.hasMoreTokens()) {
			        return true;
			    }
			    String tmp;
			    try {
			        b.mark(1000);
			        tmp = b.readLine();
			        if (tmp == null) {
			            return false;
			        }
			        b.reset();
			    } catch (IOException e) {
			        return false;
			    }
			    return true;
			}
	}
	public static class pair{
		int a;
        int b;
		public pair(int a,int b) {
			this.a=a;
			this.b=b;
		}
		@Override
		public String toString() {
			return "{"+this.a+" "+this.b+"}";
			}
	}	
		static long pow(long a, long pw) {
			long temp;
			if(pw==0)return 1;
			temp=pow(a,pw/2);
			if(pw%2==0)return mul(temp,temp);
			return mul(a,mul(temp,temp));
			
		}
		public static int md=998244353;		
		static int pow(int a, int pw) {
			int temp;
			if(pw==0)return 1;
			temp=pow(a,pw/2);
			if(pw%2==0)return temp*temp;
			return a*temp*temp;
			
		}
	
}