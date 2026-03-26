// Problem: A. Garland
// Contest: Codeforces - Codeforces Round #612 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1286/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

import java.util.*;
import java.io.*;

public class Main {
    static FastReader sc=new FastReader();
    static PrintWriter out=new PrintWriter(System.out);
    static int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
    static final double pi=3.1415926536;
    static long mod=1000000007;
    // static long mod=998244353;
    static int MAX=Integer.MAX_VALUE;
    static int MIN=Integer.MIN_VALUE;
    static long MAXL=Long.MAX_VALUE;
    static long MINL=Long.MIN_VALUE;
    static ArrayList<Integer> graph[];
    static long fact[];
    static long seg[];
    // static int dp[][];
    static long dp[][];
    public static void main (String[] args) throws java.lang.Exception {
        // code goes here
		var n = I();
		var inf = 0x3f3f3f3f;
		int[][] dp = new int[n / 2 + 1][2];
		for(int j = 1; j <= n / 2; j++){
			dp[j][0] = inf;
			dp[j][1] = inf;
		}
		var v = 0;
		for(int i = 1; i <= n; i++){
			v = I();
			for(int j = n / 2; j >= 0; j--){
				if(v == 0 || v % 2 == 1){
					dp[j][1] = Math.min(dp[j][0] + 1, dp[j][1]);
				}else{
					dp[j][1] = inf;
				}
				if(j > 0 && v % 2 == 0){
					dp[j][0] = Math.min(dp[j - 1][0], dp[j - 1][1] + 1);
				}else{
					dp[j][0] = inf;
				}
				
			}
		}
		out.println(Math.min(dp[n / 2][0], dp[n / 2][1]));
        out.close();
    }

    static class Pair implements Comparable<Pair> {
        int x, y, idx;
 
        public Pair(int x, int y, int idx) {
            this.x = x;
            this.y = y;
            this.idx = idx;
        }
 
        @Override
        public boolean equals(Object o) {
            Pair pair = (Pair) o;
            return x == pair.x && y == pair.y;
        }
 
        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
 
        @Override
        public int compareTo(Pair o) {
            return x == o.x ? y - o.y : (x - o.x);
        }
    }

    public static int[] I(int n, int s){int a[]=new int[n + s];for(int i=s;i<n + s;i++){a[i]=I();}return a;}
    public static long[] IL(int n, int s){long a[]=new long[n + s];for(int i=s;i<n + s;i++){a[i]=L();}return a;}
    
    public static int I(){return sc.I();}
    public static long L(){return sc.L();}
    public static String S(){return sc.S();}
    public static double D(){return sc.D();}
}
class FastReader {
    BufferedReader br;
    StringTokenizer st;
    public FastReader(){
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next(){
        while (st == null || !st.hasMoreElements()){
            try {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e){
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
    int I(){ return Integer.parseInt(next());}
    long L(){ return Long.parseLong(next());}
    double D(){return Double.parseDouble(next());}
    String S(){
        String str = "";
        try {
            str = br.readLine();
        }
        catch (IOException e){
            e.printStackTrace();
        }
        return str;
    }
}
