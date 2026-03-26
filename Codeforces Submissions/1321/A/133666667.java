import java.io.*;
import java.math.*;
import java.util.*;
 
public class A {
	
	public static void main(String[] agrs) {
		FastScanner sc = new FastScanner();
//		int yo = sc.nextInt();
//		while(yo-->0) {
			 int n = sc.nextInt();
			 int[] r = sc.readArray(n);
			 int[] b = sc.readArray(n);
			 boolean isEqual = true;
			 boolean isZero = true;
			 boolean isSpecial = true;
			 for(int i = 0; i < n; i++) {
				 if(r[i] != b[i]) {
					 isEqual = false;
				 }
				 if(r[i]==1) {
					 isZero = false;
				 }
				 if(r[i] == 1 && b[i] == 0) {
					 isSpecial = false;
				 }
			 }
			 if(isEqual || isZero || isSpecial) {
				 System.out.println(-1);
				 return;
			 }
			 
			 List<Integer> indexes = new ArrayList<>();
			 for(int i = 0; i < n; i++) {
				 if(r[i] == 1 && b[i] == 0) {
					 indexes.add(i);
				 }
			 }
			 
			 int[] res = new int[n];
			 Arrays.fill(res, 1);
			 for(int i = 1; i <= 1000; i++) {
				 for(int j = 0; j < indexes.size(); j++) {
					 res[indexes.get(j)] = i;
				 }
				 int rScore = cal(r,res);
				 int bScore = cal(b,res);
				 if(rScore > bScore) {
					 System.out.println(i);
					 break;
				 }
			 }
			 
		}
//	} 
	
	static int cal(int[] arr, int[] res) {
		int ans = 0;
		for(int i = 0; i < arr.length; i++) {
			ans += arr[i] * res[i];
		}
		return ans;
	}
	

	



	static int mod = 1000000007;
	static long pow(int a, int b) {
		if(b == 0) {
			return 1;
		}
		if(b == 1) {
			return a;
		}
		if(b%2 == 0) {
			long ans = pow(a,b/2);
			return ans*ans;
		}
		else {
			long ans = pow(a,(b-1)/2);
			return a * ans * ans;
		}
		
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
	}
 
}