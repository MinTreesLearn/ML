import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class JaiShreeRam{
	static Scanner in=new Scanner();
	static long systemTime;
	static long mod = 1000000007;
	static ArrayList<ArrayList<Integer>> adj;
	static int seive[]=new int[1000001];
	static long C[][];
	static int fen[]=new int[4*100005];
	static long nt=0;
	static ArrayList<Integer> ans=new ArrayList<>();
	public static void main(String[] args) throws Exception{
		int z=1;
		for(int test=1;test<=z;test++) {
			//setTime();
			solve();
			//printTime();
			//printMemory();
		}
	}
	static void solve() {
		int n=in.readInt();
		long m=in.readInt();
		long a[]=nla(n);
		if(n>m) {
			print(0);
			return;
		}
		long product=1;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++){
				product*=Math.abs(a[i]-a[j]);
				product%=m;
			}
		}
		print(product);
	}
	static long pow(long n, long m) {
		if(m==0)
			return 1;
		else if(m==1)
			return n;
		else {
			long r=pow(n,m/2);
			if(m%2==0)
				return (r*r);
			else
				return (r*r*n);
		}
	}
	static long maxsumsub(ArrayList<Long> al) {
		long max=0;
		long sum=0;
		for(int i=0;i<al.size();i++) {
			sum+=al.get(i);
			if(sum<0) {
				sum=0;
			}
			max=Math.max(max,sum);
		}
		return max;
	}
	static long abs(long a) {
		return Math.abs(a);
	}
	static void ncr(int n, int k){
		C= new long[n + 1][k + 1];
		int i, j;
		for (i = 0; i <= n; i++) {
		    for (j = 0; j <= Math.min(i, k); j++) {
		        if (j == 0 || j == i)
		            C[i][j] = 1;
		        else
		            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		    }
		}
	}
	static boolean isPalin(String s) {
		int i=0,j=s.length()-1;
		while(i<=j) {
			if(s.charAt(i)!=s.charAt(j)) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
	static int knapsack(int W, int wt[],int val[], int n){
		int []dp = new int[W + 1];
	    for (int i = 1; i < n + 1; i++) {
	    	for (int w = W; w >= 0; w--) {
		        if (wt[i - 1] <= w) {
		        	dp[w] = Math.max(dp[w],dp[w - wt[i - 1]] + val[i - 1]);
		    	}
	    	}
	    }
	    return dp[W];
	}
	static void seive() {
		Arrays.fill(seive, 1);
		seive[0]=0;
		seive[1]=0;
		for(int i=2;i*i<1000001;i++) {
			if(seive[i]==1) {
				for(int j=i*i;j<1000001;j+=i) {
					if(seive[j]==1) {
						seive[j]=0;
					}
				}
			}
		}
	}
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) 
			l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) 
			a[i]=l.get(i);
	}
	static void sort(long[] a) {
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) 
			l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) 
			a[i]=l.get(i);
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
	static Integer[] nIa(int n){
		Integer[] arr= new Integer[n];
		int i=0;
		while(i<n){
			arr[i++]=in.readInt();
		}
		return arr;
	}
	static Long[] nLa(int n){
		Long[] arr= new Long[n];
		int i=0;
		while(i<n){
			arr[i++]=in.readLong();
		}
		return arr;
	}
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
	static void print(long i) {
		System.out.println(i);
	}
	static void print(Object o) {
		System.out.println(o);
	}
	static void print(int a[]) {
		for(int i:a) {
			System.out.print(i+" ");
		}
		System.out.println();
	}
	static void print(long a[]) {
		for(long i:a) {
			System.out.print(i+" ");
		}
		System.out.println();
	}
	static void print(ArrayList<Long> a) {
		for(long i:a) {
			System.out.print(i+" ");
		}
		System.out.println();
	}
	static void print(Object a[]) {
		for(Object i:a) {
			System.out.print(i+" ");
		}
		System.out.println();
	}
	static void setTime() {
		systemTime = System.currentTimeMillis();
	}
	static void printTime() {
		System.err.println("Time consumed: " + (System.currentTimeMillis() - systemTime));
	}
 
	static void printMemory() {
		System.err.println("Memory consumed: " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1000 + "kb");
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