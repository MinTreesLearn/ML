import java.io.*;
import java.util.*;

public class new1{
	static FastReader s = new FastReader();
    static int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
   
    

	public static void main(String[] args)  throws IOException{

		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = 1;//s.nextInt();
		for(int z = 0; z < t; z++) {
			int n = s.nextInt();
			int m = s.nextInt();
			int p = s.nextInt();
			int[] arr1 = new int[n];
			int[] arr2 = new int[m];
			for(int i = 0; i < n; i++) arr1[i] = s.nextInt();
			for(int i = 0; i < m; i++) arr2[i] = s.nextInt();
			
			int ind = -1; 
			for(int i = 0; i < n; i++) {
				if(arr1[i] % p != 0) {
					ind = i; break;
				}
			}
			int ind2 = -1;
			for(int i = 0; i < m; i++) {
				if(arr2[i] % p != 0) {
					ind2 = i; break;
				}
			}
			System.out.println(ind + ind2);
			
			
			
		}
		
		//output.flush();
			
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