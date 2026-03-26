


import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Reg {
    static FastScanner fs = new FastScanner();
    static void solve(){
          int n = fs.nextInt();
          int[] b = fs.readIntArray(n);
          HashMap<Integer, Long> map = new HashMap<>();
          int index = 1;
          long ans = 0;
          for (int be : b){
              int offset = index-be;
              map.put(offset, map.getOrDefault(offset, (long)0)+be);
              ans = Math.max(ans, map.get(offset));
              ++index;
          }
          System.out.println(ans);
    }
    public static void main(String[] args) {
        solve();
    }


    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readIntArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long[] readLongArray(int n){
            long a[] = new long[n];
            for (int i = 0; i < n; ++i){
                a[i] = nextLong();
            }
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}
