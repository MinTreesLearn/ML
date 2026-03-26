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

		int t = 1;//s.nextInt();
		for(int z = 0; z < t; z++) {
			String str = s.next();
			int n = str.length();
			int[][] freq = new int[n + 1][26];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < 26; j++) {
					if(str.charAt(i) - 'a' == j) {
						freq[i + 1][j] = freq[i][j] + 1;
					}
					else freq[i + 1][j] = freq[i][j];
				}
			}
			int q = s.nextInt();
			for(int i = 0; i < q; i++) {
				int st = s.nextInt() - 1; int en = s.nextInt() - 1;
				if(st == en) {
					System.out.println("YES"); continue;
				}
				int count = 0;
				boolean pos = false;
				if(str.charAt(st) != str.charAt(en)) pos = true;
				for(int j = 0;  j < 26; j++) {
					if(str.charAt(st) - 'a' == j) continue;
					if(freq[en + 1][j] - freq[st][j] > 0) count++;
				}
				if(count >= 2)pos = true;
				
				
				//if(i == 12) System.out.println(str.substring(st, en + 1));
				if(pos)System.out.println("YES");
				else System.out.println("NO");
				
			}
			
			
			
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