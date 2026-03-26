import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        new Main().solve(new InputReader(System.in), new PrintWriter(System.out));
    }

    private void solve(InputReader in, PrintWriter pw) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        if (n > m) {
            pw.println(0);
        } else {
            long ans = 1;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    ans = (ans * abs(a[i] - a[j])) % m;
                }
            }
            pw.println(ans);
        }
        pw.close();
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
}