
/*
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='
 
*/
import java.util.function.Consumer;
import java.util.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.io.*;
import java.lang.Math.*;
 public class KickStart2020{
	static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){br = new BufferedReader(
           new InputStreamReader(System.in));}
        String next(){
            while (st == null || !st.hasMoreElements()) {
                try { st = new StringTokenizer(br.readLine()); }
                catch (IOException e) {e.printStackTrace();}}
            return st.nextToken();}
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next());}
        float nextFloat() {return Float.parseFloat(next());}
        String nextLine() {
            String str = "";
            try {str = br.readLine();}
            catch (IOException e) { e.printStackTrace();}
            return str; }}
	static String reverseOfString(String a) {
		StringBuilder ssd = new StringBuilder();
		for(int i = a.length() - 1; i >= 0; i--) {
			ssd.append(a.charAt(i));
		}
		return ssd.toString();
	}
	static char[] reverseOfChar(char a[]) {
		char b[] = new char[a.length];
		int j = 0;
		for(int i = a.length - 1; i >= 0; i--) {
			b[i] = a[j];
			j++;
		}
		return b;
	}
	static boolean isPalindrome(char a[]) {
		boolean hachu = true;
		for(int i = 0; i <= a.length / 2; i++) {
			if(a[i] != a[a.length - 1 - i]) {
				hachu = false;
				break;
			}
		}
		return hachu;
	} 
	static long gcd(long a, long b)
	{
	    if (b == 0)
	        return a;
	    return gcd(b, a % b);
	     
	}
	static long power(long x, long y, long mod){
	    long ans = 1;
	    x = x % mod; 
	    if (x == 0)
	      return 0; 
	    int i = 1;
	    while (y > 0){
	      if ((y & 1) != 0)
	        ans = (ans * x) % mod;
	      y = y >> 1; 
	      x = (x * x) % mod;
	    }
	    return ans;
	  }
	static boolean check(String a) {
		boolean hachu = true;
		for(int i = 0; i < a.length(); i++) {
			if(a.charAt(0) != a.charAt(i)) {hachu = false; break;}
		}
		return hachu;
	}
	static void move(char a[], int i) {
		int j = 0;
		int temp1 = i;
		while(j < i) {
			char temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j++;
			i--;
		}
		for(int k = 0; k <= temp1; k++) {
			a[k] = (a[k] == '0') ? '1' : '0';
		}
	}
	static boolean mayC(char a[]) {
		boolean hachu = false;
		for(int i = 2; i < a.length; i++) if(a[i] == 'C') {hachu = true; break;}
		return hachu;
	}
	static boolean pointChecker(int a, int b, int n, int m, int arr[][]) {
		boolean hachu = true;
		if(b + 1 < m && arr[a][b + 1] != 0) hachu = false;
		if(b - 1 > -1 && arr[a][b - 1] != 0) hachu = false;
		if(a + 1 < n && arr[a + 1][b] != 0) hachu = false;
		if(a - 1 > -1 && arr[a - 1][b] != 0) hachu = false;
		return hachu;
	}
		public static void main(String[] args) throws Exception{
			FastReader sc = new FastReader();
			PrintWriter out = new PrintWriter(System.out);
			int t = sc.nextInt();
			while(t-- > 0) {
                int n = sc.nextInt();
                int k = sc.nextInt();
                int arr[] = new int[n];
                for(int i = 0; i < n; i++) arr[i] = sc.nextInt();
                int i = 1, sum = arr[0];
                while(i < n) {
                	while(arr[i] != 0 && k >= i) {arr[i]--; k -= i; sum++;}
                	i++;
                	if(k < i) break;
                }
                out.println(sum);
			}
			out.close();
			}
			}