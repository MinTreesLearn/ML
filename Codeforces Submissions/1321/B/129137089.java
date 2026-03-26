import java.io.*;
import java.sql.Array;
import java.util.*;

public class A {
    static final Reader s = new Reader();
    static final PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
//        int t  = s.nextInt();
        int t=1;
        for(int i=1; i<=t; ++i) {
//            out.print("Case #"+i+": ");
            new Solver();
        }
        out.close();
    }
    static class Solver {
        Solver() {
           int n = s.nextInt();
           int[] a = new int[n];
           int[] b = new int[n];
           Map<Integer,Long> map = new HashMap<>();
           for(int i=0;i<n;i++){
               int v = s.nextInt();
               b[i] = v;
               a[i] = i-v;
           }
           long max=0;
           for(int i=0;i<n;i++) {
               if(!map.containsKey(a[i])){
                   map.put(a[i],(long)0);
               }
               map.put(a[i],map.get(a[i])+b[i]);
//               out.println(map);
               max = Math.max(max,map.get(a[i]));
           }
            out.println(max);
        }
    }
    static class Reader {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String next() {
            while(st==null||!st.hasMoreTokens()) {
                try {
                    st=new StringTokenizer(in.readLine());
                } catch(Exception e) {}
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }

}