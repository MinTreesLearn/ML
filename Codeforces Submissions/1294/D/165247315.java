import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        new Main().solve(new InputReader(System.in), new PrintWriter(System.out));
    }

    private void solve(InputReader in, PrintWriter pw) {
//        int tt = 1;
        int tt = in.nextInt();
        int x = in.nextInt();
        int mex = 0;
        int[] cnt = new int[x];
        while (tt-- > 0) {
            int y = in.nextInt();
            y = (y + x) % x;
            cnt[y]++;
            // 枚举mex,如果cnt[mex%x]>mex/x,则代表可以通过mex%x+nx构造出mex,此时mex++
            while (cnt[mex % x] > mex / x) {
                mex++;
            }
            pw.println(mex);
        }
        pw.close();
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        String str;
        try {
            str = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return str;
    }

    public boolean hasNext() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String nextLine = null;
            try {
                nextLine = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (nextLine == null)
                return false;
            tokenizer = new StringTokenizer(nextLine);
        }
        return true;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int[] nextArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
        }
        return a;
    }
}