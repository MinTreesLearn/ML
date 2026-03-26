
import java.util.*;
import java.io.*;

public class e {
    public static PrintWriter out;
    public static FS sc;
    public static void main(String[] Args) 
        throws Exception
    {
        sc = new FS(System.in);
        out = new PrintWriter(
              new BufferedWriter(
              new OutputStreamWriter(System.out)));

        int t = sc.nextInt();
        while (t-->0) {
            String s = sc.next();
            String a = sc.next();
            out.println((!defNo(s,a) && defYes(s,a)) ? "YES" : "NO");
        }
        
        out.close();
    }
	public static boolean defNo(String s, String a) {
            s = s + s;
            int n = s.length();
            int m = a.length();
            int fptr = 0;
            int i;
            for (i = 0; i < m; i++) {
                while (fptr < n && s.charAt(fptr) != a.charAt(i))
                    fptr++;
                if (fptr == n) break;
                fptr++;
            }
		return i!= m;
		}
	public static int[][] tried = new int[401][401];
	public static int n, m, split;
	public static char[] ss, aa;
	public static boolean defYes(String s, String a) {
		n = s.length();
		m = a.length();
		ss = new char[n];
		aa = new char[m];
		int[] count = new int[26];
		
		for (int i = 0; i < n; i++)
			count[(ss[i] = s.charAt(i))-'a']++;
		for (int i = 0; i < m; i++){
			count[(aa[i] = a.charAt(i))-'a']++;
		}
		for (int i = 0; i < 26; i++)
			if (count[i] < 0)
				return false;
		for (int j = 0; j <= m; j++) {
			split = j;
			for (int[] x : tried)
				Arrays.fill(x, n);
			if (rec(0,split,0))
				return true;
		}
		return false;
	}
	public static boolean rec(int a, int b, int c) {
		if (a == split && b == m)
			return true;
		if (tried[a][b] <= c)
			return false;
		if (a < split && ss[c] == aa[a] && rec(a+1,b,c+1))
			return true;
		if (b < m && ss[c] == aa[b] && rec(a, b+1, c+1))
			return true;
		if ((a < split && ss[c] == aa[a]) || (b < m && ss[c] == aa[b])){
			
		tried[a][b] = c;
			return false;
		}
		if (rec(a,b,c+1))
			return true;
		tried[a][b] = c;
		return false;
	}

    public static int getCurPow(long cap) {
        int curPow = 0;
        while (((1l<<curPow)&cap) == 0)
            curPow++;
        return curPow;
    }

    public static class FS {
        BufferedReader br;
        StringTokenizer st;
        FS(InputStream in) throws Exception {
            br = new BufferedReader(new InputStreamReader(in));
            st = new StringTokenizer(br.readLine());
        }
        String next() throws Exception {
            if (st.hasMoreTokens())
                return st.nextToken();
            st = new StringTokenizer(br.readLine());
            return next();
        }

        int nextInt() throws Exception {
            return Integer.parseInt(next());
        }

        long nextLong() throws Exception {
            return Long.parseLong(next());
        }

        double nextDouble() throws Exception {
            return Double.parseDouble(next());
        }
    }
}
