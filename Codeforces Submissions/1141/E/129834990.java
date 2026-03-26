import java.io.*;
import java.util.*;
import java.lang.*;
import java.util.jar.JarEntry;

import static java.lang.Math.*;

// Sachin_2961 submission //
public class Codeforces {

    static void solve() {
        long H = fs.nLong();
        int n = fs.nInt();
        int[]ar = new int[n];
        long sum = 0;
        long mn = 0;
        for(int i=0;i<n;i++){
            ar[i] = fs.nInt();
            sum += ar[i];
            mn = min(mn,sum);
            if( H + sum <= 0 ){
                out.println(i+1);
                return;
            }
        }
        if(sum < 0){
            long ans = (long)floor((double)(H+mn)/(double)(-sum));
            H += sum*ans;
            ans *= n;
            int i = 0;
            while (H > 0 ){
                ans++;
                H += ar[i%n];
                i++;
            }
            out.println(ans);
            return;
        }
        out.println("-1");
    }
    
    static boolean multipleTestCase = false; static FastScanner fs; static PrintWriter out;
    public static void main(String[]args){
       try{
           fs = new FastScanner();
           out = new PrintWriter(System.out);
           int tc = (multipleTestCase)?fs.nInt():1;
           while (tc-->0)solve();
           out.flush();
           out.close();
       }catch (Exception e){
           e.printStackTrace();
       }
    }
    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String n() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }
        String Line()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
        int nInt() {return Integer.parseInt(n()); }
        long nLong() {return Long.parseLong(n());}
        double nDouble(){return Double.parseDouble(n());}
        int[]aI(int n){
            int[]ar = new int[n];
            for(int i=0;i<n;i++)
                ar[i] = nInt();
            return ar;
        }
    }
}