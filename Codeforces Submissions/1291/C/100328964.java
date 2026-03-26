import java.util.*;
import java.io.*;
import java.math.*;
 
public class Main
{
    public static void process(int testNumber)throws IOException
    {
        int n = ni(), m = ni(), k = ni(), res = 0, arr[] = new int[n + 2]; 
        for(int i = 1; i <= n; i++)
            arr[i] = ni();

        int inFront = m - 1, canControl = Math.min(k, inFront), cantControl = inFront - canControl;
        for(int st = 0; st <= canControl; st++){
            int end = canControl - st, take = oo;
            end = n - end;
    
            for(int front = 0; front <= cantControl; front++){
                int back = cantControl - front;
                int l = st + front + 1, r = end - back;
                trace("st = " + st, "end = " + end, "front = " + front, "back = " + back, "l = " + l, "r = " + r);
                take = Math.min(take, Math.max(arr[l], arr[r]));
            }
            trace(take);
            res = Math.max(res, take);
        }

        pn(res);
    }
 
    static final long mod = (long)1e9+7l;
    static final int oo = (int) 1e9 + 12345678;
    static boolean DEBUG = false;
    static FastReader sc;
    static PrintWriter out;
    public static void main(String[]args)throws IOException
    {
        out = new PrintWriter(System.out);
        sc = new FastReader();
 
        long s = System.currentTimeMillis();
        int t = 1;
        t = ni();
        for(int i = 1; i <= t; i++)
            process(i);
 
        out.flush();
        System.err.println(System.currentTimeMillis()-s+"ms");
    }

    static void trace(Object... o){ if(!DEBUG) return; System.err.println(Arrays.deepToString(o)); };    
    static void pn(Object o){ out.println(o); }
    static void p(Object o){ out.print(o); }
    static int ni()throws IOException{ return Integer.parseInt(sc.next()); }
    static long nl()throws IOException{ return Long.parseLong(sc.next()); }
    static double nd()throws IOException{ return Double.parseDouble(sc.next()); }
    static String nln()throws IOException{ return sc.nextLine(); }
    static long gcd(long a, long b){ return (b==0)?a:gcd(b,a%b);}
    static int gcd(int a, int b){ return (b==0)?a:gcd(b,a%b); }
    
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
