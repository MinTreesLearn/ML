import java.io.*;
import java.util.*;

public class Main {
    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();

        if (n <= 3) {
            char[] s = new char[n];
            for (int i = 1; i <= n; ++i) {
                out.println("? " + i + " " + i);
                out.flush();
                s[i - 1] = in.next().toCharArray()[0];
            }
            out.println("! "  + new String(s));
            return;
        }

        out.println("? 1 " + n);
        out.flush();
        List<String> s1 = new ArrayList<>();
        for (int i = 0; i < (n + 1) * n / 2; ++i) {
            char[] s = in.next().toCharArray();
            Arrays.sort(s);
            s1.add(new String(s));
        }
        Collections.sort(s1);
        out.println("? 2 " + n);
        out.flush();
        List<String> s2 = new ArrayList<>();
        for (int i = 0; i < (n - 1) * n / 2; ++i) {
            char[] s = in.next().toCharArray();
            Arrays.sort(s);
            s2.add(new String(s));
        }
        Collections.sort(s2);

        List<String> t1;
        t1 = new ArrayList<>(s1);
        for (String s : s2) {
            t1.remove(s);
        }

        Collections.sort(t1, Comparator.comparingInt(String::length));

        char[] s = new char[n];
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                s[0] = t1.get(i).charAt(0);
                continue;
            }
            int[] count = new int[26];
            for (char c: t1.get(i - 1).toCharArray()) {
                count[c - 'a']--;
            }
            for (char c: t1.get(i).toCharArray()) {
                count[c - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                if (count[j] > 0) {
                    s[i] = (char) (j + 'a');
                }
            }
        }

        out.println("! " + new String(s));
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Main().solve(in, out);
        out.flush();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}

/**
5
x
a
s
d
xa
as
sd
xas
asd
xasd
s
d
u
a
sd
du
ua
sdu
dua
sdua

4
x
a
y
t
xa
ay
yt
xay
ayt
xayt
a
y
t
ay
yt
ayt
 **/