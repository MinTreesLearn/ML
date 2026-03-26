import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {

    public static void main(String[] args) {

        Parser parser = new Parser();
        int t = 1;
        for (int i = 1; i <= t; i++) {
            Problem problem = new Problem();
            problem.solve(i);
        }
    }
}

class Problem {
    private Parser parser = new Parser();

    public void solve() {

    }

    public void solve(int testNum) {
        int n = parser.parseInt();
        int[] b = new int[n];

        for(int i = 0; i < n; i++) {
            b[i] = parser.parseInt() - i;
        }

        Map<Integer, Long> counts = new HashMap<>();
        Map<Integer, Long> sums = new HashMap<>();
        for(int i = 0; i < n; i++) {
            int v = b[i];
            counts.put(v, counts.getOrDefault(v, 0L) + 1);
            sums.put(v, sums.getOrDefault(v, 0L) + i);
        }

        long ans = 0;
        for(int v : counts.keySet()) {
            ans = Math.max(ans, (long)counts.get(v) * v + sums.get(v));
        }
        System.out.println(ans);
    }

    public static long pow(long x, long y) {
        return pow(x, y, Function.identity());
    }

    public static long pow(long x, long y, long mod) {
        return pow(x, y, v -> v % mod);
    }

    private static long pow(long x, long y, Function<Long, Long> action) {
        long res = 1;
        long t = x;
        while (y > 0) {
            if ((y & 1) == 1) {
                res *= t;
                res = action.apply(res);
            }
            t *= t;
            t = action.apply(t);
            y /= 2;
        }
        return res;
    }
}

class DisjointSet {

    private final int[] f;

    public DisjointSet(int size) {
        f = new int[size + 1];
        for (int i = 0; i <= size; i++) {
            f[i] = i;
        }
    }

    public int find(int u) {
        if (f[u] == u) return u;
        return f[u] = find(f[u]);
    }

    public boolean merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (u > v) {
            int t = u;
            u = v;
            v = t;
        }
        f[u] = v;
        return true;
    }
}

class IntPair {
    private int l;
    private int r;

    public IntPair(int l, int r) {
        this.l = l;
        this.r = r;
    }

    public int getL() {
        return l;
    }

    public void setL(int l) {
        this.l = l;
    }

    public int getR() {
        return r;
    }

    public void setR(int r) {
        this.r = r;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        IntPair pair = (IntPair) o;
        return l == pair.l &&
                r == pair.r;
    }

    @Override
    public int hashCode() {
        return Objects.hash(l, r);
    }
}

class Parser {
    public static final Parser PARSER = new Parser();
    private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private StringTokenizer tokenizer;

    public int parseInt() {
        fill();
        return Integer.parseInt(tokenizer.nextToken());
    }

    public long parseLong() {
        fill();
        return Long.parseLong(tokenizer.nextToken());
    }

    public double parseDouble() {
        fill();
        return Double.parseDouble(tokenizer.nextToken());
    }

    public String parseLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    String parseString() {
        fill();
        return tokenizer.nextToken();
    }

    private void fill() {
        while (tokenizer == null || !tokenizer.hasMoreElements()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}