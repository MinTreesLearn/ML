import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class JaiShreeRam{
	static Scanner in=new Scanner();
	static long mod = 1000000007;
	static ArrayList<ArrayList<Integer>> adj;
	static ArrayList<String> ans;
	public static void main(String[] args) throws Exception{
		int z=in.readInt();
		while(z-->0) {
			solve();
		}
	}	
	static void solve() {
		int n=in.readInt();
		int x=in.readInt();
		int a[]=nia(n);
		Set<Integer> st=new HashSet<>();
		int max=a[0];
		for(int i=0;i<n;i++) {
			max=Math.max(max, a[i]);
			st.add(a[i]);
		}
		if(st.contains(x)) {
			System.out.println(1);
		}
		else if(x<max) {
			System.out.println(2);
		}
		else {
			System.out.println((int)Math.ceil((double)x/max));
		}
	}
	static int[] nia(int n){
		int[] arr= new int[n];
		int i=0;
		while(i<n){
			arr[i++]=in.readInt();
		}
		return arr;
	}
	static long[] nla(int n){
		long[] arr= new long[n];
		int i=0;
		while(i<n){
			arr[i++]=in.readLong();
		}
		return arr;
	}
	static int[] nia1(int n){
		int[] arr= new int[n+1];
		int i=1;
		while(i<=n){
			arr[i++]=in.readInt();
		}
		return arr;
	}
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
	static class Scanner{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String readString() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		double readDouble() {
			return Double.parseDouble(readString());
		}
		int readInt() {
			return Integer.parseInt(readString());
		}
		long readLong() {
			return Long.parseLong(readString());
		}
	}	
}