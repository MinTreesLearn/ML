// ＼(≧▽≦)／

import java.io.*;
import java.util.*;

public class tank {

    static final FastScanner fs = new FastScanner();

    //static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while(t-- > 0) {
            run_case();
        }

        //out.close();
    }

    static void run_case() {
        int n = fs.nextInt(), k =fs.nextInt();
        char[][] s = new char[n][];

        for (int i = 0; i < n; i++) {
            s[i] = fs.next().toCharArray();
        }

        HashSet<String> hs = new HashSet<>();

        for (int i = 0; i < n; i++) {
            hs.add(new String(s[i]));
        }

        long ans = 0;

        char[] tr = {'S', 'E', 'T'};

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                char[] nw = new char[k];
                for (int l = 0; l < k; l++) {
                    if(s[i][l] == s[j][l]) {
                        nw[l] = s[i][l];
                    }else {
                        for (int m = 0; m < 3; m++) {
                            if(s[i][l] != tr[m] &&
                            s[j][l] != tr[m]) {
                                nw[l] = tr[m];
                            }
                        }
                    }
                }

                if(hs.contains(new String(nw))) ans++;
            }
        }

        System.out.println(ans / 3);
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