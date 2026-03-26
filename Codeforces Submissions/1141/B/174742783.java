/* package codeForces; // don't place package name! */
// algo_messiah23 , NIT RKL ...
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
import static java.lang.System.*;
import java.util.stream.IntStream;
 
import java.util.Map.Entry;
 
/* Name of the class has to be "Main" only if the class is public. */
public class CodeForces {
	static PrintWriter out = new PrintWriter((System.out));
	static FastReader in = new FastReader();
	static int INF = Integer.MAX_VALUE;
	static int NINF = Integer.MIN_VALUE;
 
	public static void main(String[] args) throws java.lang.Exception {
		// your code goes here
		int t = 1;
		//t = i();
		while (t-- > 0)
			algo_messiah23();
		out.close();
	}
 
	public static void algo_messiah23() {
	    int n = i();
	    int a[] = input(n);
	    List<Integer> list = new ArrayList<>();
	    for(int i : a)
	    list.add(i);
	    for(int i : a)
	    list.add(i);
	    int maxe = NINF;
	    int c = 0;
	    for(int i=0;i<list.size();i++){
	        if(list.get(i) == 1)
	        c++;
	        else{
	            maxe = (int)Math.max(c,maxe);
	            c = 0;
	        }
	    }
	    out.println(maxe);
	}
	
	static String rev(String s) {
		StringBuilder st = new StringBuilder(s);
		st.reverse();
		String ans = st.toString();
		return ans;
	}
	
	static int[] input(int N) {
		int[] A = new int[N];
		for (int i = 0; i < N; i++)
			A[i] = in.nextInt();
		return A;
	}
 
	public static void print(int[] arr) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			out.print(arr[i] + " ");
		}
		out.println();
	}
 
	public static void sort(int[] arr) {
		ArrayList<Integer> ls = new ArrayList<>();
		for (int x : arr) {
			ls.add(x);
		}
		Collections.sort(ls);
		for (int i = 0; i < arr.length; i++) {
			arr[i] = ls.get(i);
		}
	}
 
	public static void reverse(int[] arr) {
		int n = arr.length;
		for (int i = 0; i < n / 2; i++) {
			int temp = arr[i];
			arr[i] = arr[n - 1 - i];
			arr[n - 1 - i] = temp;
		}
	}
 
	public static void reverse(long[] arr) {
		int n = arr.length;
		for (int i = 0; i < n / 2; i++) {
			long temp = arr[i];
			arr[i] = arr[n - 1 - i];
			arr[n - 1 - i] = temp;
		}
	}
 
	public static void print(ArrayList<Integer> arr) {
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			out.print(arr.get(i) + " ");
		}
		out.println();
	}
 
	static int i() {
		return in.nextInt();
	}
 
	static long l() {
		return in.nextLong();
	}
 
	static char ich() {
		return in.next().charAt(0);
	}
 
	static String is() {
		return in.next();
	}
 
	static String isl() {
		return in.nextLine();
	}
 
	public static int max(int[] arr) {
		int max = -1;
		int n = arr.length;
		for (int i = 0; i < n; i++)
			max = Math.max(max, arr[i]);
		return max;
	}
 
	public static int min(int[] arr) {
		int min = INF;
		int n = arr.length;
		for (int i = 0; i < n; i++)
			min = Math.min(min, arr[i]);
		return min;
	}
 
	public static int gcd(int x, int y) {
		if (y == 0) {
			return x;
		}
		return gcd(y, x % y);
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
 
	int nextInt() {
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
	}
}