import java.io.*;
import java.util.*;

public class tank {

    static final FastScanner fs = new FastScanner();

    //static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = fs.nextInt();
        while(t-->0) {
            run_case();
        }

        //out.close();
    }

    static void run_case() {
        int n = fs.nextInt(), m = fs.nextInt(), k = fs.nextInt();
        int[] arr = fs.readArray(n);

        if(m == 1) {
            System.out.println(Math.max(arr[0], arr[n - 1]));
            return;
        }

        ArrayList<Integer> al = new ArrayList<>();

        if(k > m - 1) k = m - 1;

        int l = k, r = 0, ans = Integer.MAX_VALUE, cur = 0;

        for (int i = 0; i <= m - 1; i++) {
            al.add(Math.max(arr[i], arr[i + n - m]));
        }

        while(l >= 0) {
            for (int i = l; i <= m - r - 1; i++) {
                ans = Math.min(ans, al.get(i));
            }

            l--;
            r++;
            cur = Math.max(cur, ans);
            ans = Integer.MAX_VALUE;
        }

        System.out.println(cur);
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

        String nextLine(){
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return "";
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}