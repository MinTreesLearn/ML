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
		 
//		 InverseofNumber(m);
//	     InverseofFactorial(m);
//	     factorial(m);
//		 
        while(tc--!=0) {
        	 int n=sc.nextInt();
        	 int h=sc.nextInt();
        	 int l=sc.nextInt();
        	 int r=sc.nextInt();
        	 int a[]=new int[n];
        	 for(int i=0;i<n;i++)a[i]=sc.nextInt();
        	 dp=new int[n][h+1];
        	 for(int i=0;i<n;i++)Arrays.fill(dp[i], -1);
        	 log.write(eval(a,0,0,h,l,r)+"\n");
        	 
        	  log.flush();
        	 
        }        
	        

	 
		}
static int eval(int a[],int i,int ch,int h,int l,int r) {
	if(i>=a.length)return (ch>=l && ch<=r)?1:0;
	if(dp[i][ch]!=-1)return dp[i][ch];
    return dp[i][ch]=(i>0 && ch>=l && ch<=r?1:0)+Math.max(eval(a,i+1,(ch+a[i]-1+h)%h,h,l,r), eval(a,i+1,(ch+a[i]+h)%h,h,l,r));
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