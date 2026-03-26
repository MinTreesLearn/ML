import java.util.*;
import java.io.*;

public class Main {
	static StringBuilder sb;
	static dsu dsu;
	static long fact[];
	static int mod = (int) (1e9 + 7);

	static void solve() {
	  int n=i();
	  String s=s();
// ...../////..........
	  ArrayList<Character> arr=new ArrayList<>();
	  for(int i=0;i<n;i++){
	     arr.add(s.charAt(i));
	      
	  }
	  boolean b=true;
	 while(b&&arr.size()>1){
	     
	     HashMap<Character,ArrayList<Integer>> hm=new HashMap<>();
	     for(int j=0;j<26;j++){
	         char temp=(char)(j+'a');
	         hm.put(temp,new ArrayList<>());
	     }
	 for(int i=0;i<arr.size();i++){
	    char ch=arr.get(i);
	    if(i==0){
	          char ch1=arr.get(i+1);
	          if((char)(ch1+1)==(ch)){
	              hm.get(ch).add(i);
	          }
	        
	    }
	    else if(i==arr.size()-1){
	         char ch1=arr.get(i-1);
	          if((char)(ch1+1)==(ch)){
	              hm.get(ch).add(i);
	          }
	    }
	    else{
	        
	         char ch1=arr.get(i+1);
	          if((char)(ch1+1)==(ch)){
	              hm.get(ch).add(i);
	          }
	          else{
	             ch1=arr.get(i-1);
	          if((char)(ch1+1)==(ch)){
	              hm.get(ch).add(i);
	          }
	        
	          }
	    }
	     
	 }
	 ArrayList<Integer> tr=new ArrayList<>();
	 char curr='a';
	boolean b1=false;
	  for(char ch: hm.keySet()){
	      if(hm.get(ch).size()==0)continue;
	      b1=true;
	      if(ch>=curr){
	          curr=ch;
	          tr=hm.get(ch);
	      }
	  }
	  HashSet<Integer> hs=new HashSet<>();
	  
	  for(int t:tr)hs.add(t);
	  
	  ArrayList<Character> final2=new ArrayList<>();
	  
	 for(int j=0;j<arr.size();j++){
	     if( !hs.contains(j)  ){
	         final2.add(arr.get(j));
	     }
	 }
	  
	
	  arr=new ArrayList<>();
	  for(char t:final2){
	     arr.add(t);
	  }
	  
	  b=b1;
	  
	 }
	  
	  sb.append(n-arr.size()+"\n");  
	}
	
	    
	    
	    
	

	public static void main(String[] args) {
		sb = new StringBuilder();
		int test =1;
     fact=new long[(int)1e6+10];
			 fact[0]=fact[1]=1; 
			 for(int i=2;i<fact.length;i++)
	 { fact[i]=((long)(i%mod)*(long)(fact[i-1]%mod))%mod; }

		while (test-- > 0) {
			solve();
		}
		System.out.println(sb);

	}


//**************NCR%P******************	 
	static long ncr(int n, int r) {
		if (r > n)
			return (long) 1;

		long res = fact[n] % mod;
		// System.out.println(res);
		res = ((long) (res % mod) * (long) (p(fact[r], mod - 2) % mod)) % mod;
		res = ((long) (res % mod) * (long) (p(fact[n - r], mod - 2) % mod)) % mod;
		// System.out.println(res);
		return res;

	}

	static long p(long x, long y)// POWER FXN //
	{
		if (y == 0)
			return 1;

		long res = 1;
		while (y > 0) {
			if (y % 2 == 1) {
				res = (res * x) %mod;
				y--;
			}

			x = (x * x) %mod;
			y = y / 2;

		}
		return res;
	}

//**************END******************

	// *************Disjoint set
	// union*********//
	static class dsu {
		int parent[];

		dsu(int n) {
			parent = new int[n];
			for (int i = 0; i < n; i++)
				parent[i] = -1;
		}

		int find(int a) {
			if (parent[a] < 0)
				return a;
			else {
				int x = find(parent[a]);
				parent[a] = x;
				return x;
			}
		}

		void merge(int a, int b) {
			a = find(a);
			b = find(b);
			if (a == b)
				return;
			parent[b] = a;
		}
	}

//**************PRIME FACTORIZE **********************************//
	static TreeMap<Integer, Integer> prime(long n) {
		TreeMap<Integer, Integer> h = new TreeMap<>();
		long num = n;
		for (int i = 2; i <= Math.sqrt(num); i++) {
			if (n % i == 0) {
				int nt = 0;
				while (n % i == 0) {
					n = n / i;
					nt++;
				}
				h.put(i, nt);
			}
		}
		if (n != 1)
			h.put((int) n, 1);
		return h;

	}

//****CLASS PAIR ************************************************
	static class Pair implements Comparable<Pair> {
	int dx;
	int dy;
		Pair() {
		
		}

		public int compareTo(Pair o) {
		if(this.dx!=o.dx)	return (int) (this.dx - o.dx);
else return (int) (this.dy - o.dy);
		}

	}
	static class Pair1 implements Comparable<Pair1> {
		int idx;
		long w;

		Pair1(int idx, long w) {
			this.idx = idx;
			this.w = w;
		}

		public int compareTo(Pair1 o) {
			return (int) (this.w - o.w);

		}

	}
	
	static class PairF implements Comparable<PairF> {
	
	    int i;
	    long x;
		PairF( int i,long x) {
			this.x = x;
		
			this.i=i;
		}

		public int compareTo(PairF o) {
			return (int) (this.x - o.x);

		}

	}
//****CLASS PAIR **************************************************

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int Int() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String String() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String next() {
			return String();
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void printLine(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void flush() {
			writer.flush();
		}
	}

	static InputReader in = new InputReader(System.in);
	static OutputWriter out = new OutputWriter(System.out);

	public static long[] sort(long[] a2) {
		int n = a2.length;
		ArrayList<Long> l = new ArrayList<>();
		for (long i : a2)
			l.add(i);
		Collections.sort(l);
		for (int i = 0; i < l.size(); i++)
			a2[i] = l.get(i);
		return a2;
	}

	public static char[] sort(char[] a2) {
		int n = a2.length;
		ArrayList<Character> l = new ArrayList<>();
		for (char i : a2)
			l.add(i);
		Collections.sort(l);
		for (int i = 0; i < l.size(); i++)
			a2[i] = l.get(i);
		return a2;
	}

	public static long pow(long x, long y) {
		long res = 1;
		while (y > 0) {
			if (y % 2 != 0) {
				res = (res * x);// % modulus;
				y--;

			}
			x = (x * x);// % modulus;
			y = y / 2;
		}
		return res;
	}

//GCD___+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	public static long gcd(long x, long y) {
		if (x == 0)
			return y;
		else
			return gcd(y % x, x);
	}
	// ******LOWEST COMMON MULTIPLE
	// *********************************************

	public static long lcm(long x, long y) {
		return (x * (y / gcd(x, y)));
	}

//INPUT PATTERN********************************************************
	public static int i() {
		return in.Int();
	}

	public static long l() {
		String s = in.String();
		return Long.parseLong(s);
	}

	public static String s() {
		return in.String();
	}

	public static int[] readArrayi(int n) {
		int A[] = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = i();
		}
		return A;
	}

	public static long[] readArray(long n) {
		long A[] = new long[(int) n];
		for (int i = 0; i < n; i++) {
			A[i] = l();
		}
		return A;
	}

}