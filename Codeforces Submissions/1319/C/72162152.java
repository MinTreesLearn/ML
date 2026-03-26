import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        String a = in.next();
        int x = 25;
        while (true) {
            boolean act = false;
            for (int i = x; i > 0; i--) {
                x = i;
                for (int j = 0; j < a.length(); j++) {
                    if (a.charAt(j) - 'a' == i)
                        if ((j > 0 && a.charAt(j - 1) + 1 == a.charAt(j)) || (j < a.length() - 1 && a.charAt(j + 1) + 1 == a.charAt(j))) {
                            String g = "";
                            for (int k = 0; k < j; k++) {
                                g += a.charAt(k);
                            }
                            for (int k = j + 1; k < a.length(); k++) {
                                g += a.charAt(k);
                            }
                            a = g;
                            act = true;
                            break;
                        }
                }
                if (act) break;
            }
            if (!act) break;
        }
        in.out.println(n - a.length());
        in.out.close();
    }
}

class FastScanner {

    StringTokenizer st = new StringTokenizer("");
    BufferedReader br;
    PrintWriter out;


    FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }


    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
