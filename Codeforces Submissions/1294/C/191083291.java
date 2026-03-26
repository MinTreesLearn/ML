import java.io.*;
import java.util.*;

public class Tournament {
    static FastScanner sc = new FastScanner();

    public static void main(String[] args){
        int t = sc.nextInt();
        // sc.nextLine();
        // int t = 1;
        while( t--> 0){
            solve();
        }
    }
 
    public static void solve(){
        long n = sc.nextLong();
        long a=0, b=0;
            for (int i=2;(i*i)<n;i++) {
                if (n%i==0){
                    n/=i;
                    if(a==0)  a = i;
                    else{
                        b = i;
                        break;
                    }
                }
            }
 
            if(a!=0 && b!=0 && n>b){
                System.out.println("YES");
                System.out.println(a + " " + b + " " + n);
            }else System.out.println("NO");
}

    
    static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
		    return Double.parseDouble(next());
		}
}
}


