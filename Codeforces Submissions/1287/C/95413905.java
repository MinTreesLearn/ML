import java.util.*;
import java.io.*;
import java.math.*;
 
public class C
{
    static int colorGarland(int idx, int odds, int eves, int prev, int n){
        if(idx > n)
            return 0;

        if(dp[idx][odds][eves][prev] != -1)
            return dp[idx][odds][eves][prev];

        int q1 = oo, q2 = oo;

        if(arr[idx] == -1){
            if(odds < n / 2 + (n & 1)){
                q1 = (prev != 1 ? 1 : 0) + colorGarland(idx + 1, odds + 1, eves, 1, n);
            }

            if(eves < n / 2){
                q2 = (prev != 0 ? 1 : 0) + colorGarland(idx + 1, odds, eves + 1, 0 , n);
            }
        }
        else if(arr[idx] == 0){
            if(eves < n / 2)
                q1 = (prev != 0 ? 1 : 0) + colorGarland(idx + 1, odds, eves + 1, 0, n);
        }
        else{
            if(odds < n / 2 + (n & 1))
                q1 = (prev != 1 ? 1 : 0) + colorGarland(idx + 1, odds + 1, eves, 1, n);
        }

        return dp[idx][odds][eves][prev] = Math.min(q1, q2);
    }

    public static void process(int test_number)throws IOException
    {
        int n = ni();
        arr = new int[n + 1];
        dp = new int[n + 1][n / 2 + (n & 1) + 1][n / 2 + 1][2];

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n / 2 + (n & 1); j++)
                for(int k = 0; k <= n / 2; k++)
                    for(int l = 0; l <= 1; l++)
                        dp[i][j][k][l] = -1; 


        for(int i = 1; i <= n; i++){
            int x = ni();
            arr[i] = (x == 0) ? -1 : (x % 2);
        }

        int res = oo;
        if(n == 1)
            res = 0;
        else if(arr[1] == -1){
            res = Math.min(colorGarland(2, 1, 0, 1, n), 
                                colorGarland(2, 0, 1, 0, n));
        }
        else if(arr[1] == 1)
            res = colorGarland(2, 1, 0, 1, n);
        else
            res = colorGarland(2, 0, 1, 0, n);

        pn(res);
    }
     
    static int dp[][][][], arr[];  // states : (idx, odds, evens, prev)
    static final int oo = (int) 1e8;
    static final long mod = (long)1e9+7l;
    
    static FastReader sc;
    static PrintWriter out;
    public static void main(String[]args)throws IOException
    {
        out = new PrintWriter(System.out);
        sc = new FastReader();
 
        long s = System.currentTimeMillis();
        int t = 1;
        //t = ni();
        for(int i = 1; i <= t; i++)
            process(i);
 
        out.flush();
        System.err.println(System.currentTimeMillis()-s+"ms");
    }

    static void trace(Object... o){ System.err.println(Arrays.deepToString(o)); };
    static void pn(Object o){ out.println(o); }
    static void p(Object o){ out.print(o); }
    static int ni()throws IOException{ return Integer.parseInt(sc.next()); }
    static long nl()throws IOException{ return Long.parseLong(sc.next()); }
    static double nd()throws IOException{ return Double.parseDouble(sc.next()); }
    static String nln()throws IOException{ return sc.nextLine(); }
    static long gcd(long a, long b)throws IOException{ return (b==0)?a:gcd(b,a%b);}
    static int gcd(int a, int b)throws IOException{ return (b==0)?a:gcd(b,a%b); }
    static int bit(long n)throws IOException{ return (n==0)?0:(1+bit(n&(n-1))); }
    
    static class FastReader{ 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(){ 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next(){ 
            while (st == null || !st.hasMoreElements()){ 
                try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); } 
            } 
            return st.nextToken(); 
        } 
  
        String nextLine(){ 
            String str = ""; 
            try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); } 
            return str; 
        } 
    } 
}
