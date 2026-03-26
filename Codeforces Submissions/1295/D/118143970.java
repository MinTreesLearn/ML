import java.io.*;
import java.util.*;

public class D{
	
	static long gcd(long a, long b) {
		if (a == 0) return b;
		return gcd(b%a, a);
	}
	static long bf(long a, long m) {
		long cnt = 0;
		long gcd = gcd(a,m);
		for (int i = 0; i < m; i++) cnt += gcd(a+i,m)==gcd ? 1:0;
		return cnt;
	}
	static long pp(long a, long m) {
		long g = gcd(a,m);
		a/=g;
		m/=g;
		long ans = m;
		for (long i = 2; i *i<=m; i++) {
			if (m % i == 0) {
				while(m%i==0) m/=i;
				ans -= ans/i;
			}
		}
		if (m > 1) ans -= ans/m;
		return ans;
	}
	
	static List<Long> p;
	public static void main(String[] args) throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		//new Thread(null, new (), "peepee", 1<<28).start();
		
		boolean[] sieve = new boolean[(int)1e6+20];
		p = new ArrayList<Long>();
		for (int i = 2; i *i <= sieve.length; i++) {
			if (!sieve[i]) {
				for (int j = i*i; j < sieve.length; j+=i) sieve[j] = false;
			}
		}
		for (int i = 2; i < sieve.length; i++) if (!sieve[i]) p.add((long)i);
		
//		long a = (long)(Math.random()*1e3+1);
//		long b = a + (long)(Math.random()*1e2+12);
//		for (int i = 1; i < 10; i++) {
//			long ta = a*i;
//			long tb = b*i;
//			out.println(bf(ta,tb) + " " + pp(ta,tb));
//		}
		
		readInput();
		out.close();
	}
	
	static void readInput() throws IOException{
		read();
		int t= RI();
		while(t-->0) {
			read();
			long a = RL();
			long m = RL();
			out.println(pp(a,m));
		}
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	static StringTokenizer st;
	static void read() throws IOException{st = new StringTokenizer(br.readLine());}	
	static int RI() throws IOException{return Integer.parseInt(st.nextToken());}
	static long RL() throws IOException{return Long.parseLong(st.nextToken());}
	static double RD() throws IOException{return Double.parseDouble(st.nextToken());}
	
}
