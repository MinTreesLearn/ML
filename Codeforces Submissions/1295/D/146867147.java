import java.io.*;
import java.util.*;
// #FullSolution
public class new1{
	public static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
         
        return gcd(b%a, a);
    }
	
	
	static FastReader s = new FastReader();

	public static void main(String[] args)  throws IOException{

		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
		int n1 = 1000000;
		int[] seive = new int[n1];
		for(int i = 2; i < n1; i++) {
			for(int j = i; j < n1; j = j + i) {
				if(seive[j] == 0) seive[j] = i;
			}
		}
		
		
		
		int t = s.nextInt();
		for(int z = 0; z < t; z++) {
			long a = s.nextLong();
			long m = s.nextLong();
			long gcd = gcd(a, m);
			a = a / gcd;
			m = m / gcd;
			long aa = m; int count = 0;
			//System.out.println(a + " " + m);
			int n = (int) Math.sqrt(m) + 5;
			for(int i = 2; i < n; i++) {
				if(seive[i] == i && m % i == 0) {
					if(aa % i == 0) {
						aa = (aa / i) * (i - 1L);
					}
					else aa = (aa / (i - 1)) * i;
					while(m % i == 0) m = m / i;
				}
			}
			if(m > 1) {
				if(aa % m == 0) {
					aa = (aa / m) * (m - 1L);
				}
				else aa = (aa / (m - 1)) * m;
				
			}
			System.out.println(aa);
			
			
			
		}
		
		output.flush();
			
	  }
}


 
class FastReader {
    BufferedReader br;
    StringTokenizer st;
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
 
    public int nextInt() {
        return Integer.parseInt(next());
    }
 
    long nextLong() {
        return Long.parseLong(next());
    }
 
    double nextDouble() {
        return Double.parseDouble(next());
    }
 
    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
}}