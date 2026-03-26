import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.function.BiFunction;
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
    int n;
    int[] p;
    int[][][][] dp = new int[100][2][59][59];

    public void solve() {
    }

    public void solve(int testNum) {
        dp = new int[109][2][59][59];
        for(int i = 0; i < 109; i++) {
            for(int j = 0; j < 59; j++) {
                Arrays.fill(dp[i][0][j], -1);
                Arrays.fill(dp[i][1][j], -1);
            }
        }

        n = parser.parseInt();
        p = new int[n + 1];
        int odds = n / 2 + n % 2;
        int evens = n / 2;
        for(int i = 1; i <= n; i++) {
            p[i] = parser.parseInt();
            if(p[i] == 0) {
                continue;
            }
            if(p[i] % 2 == 0) {
                evens -= 1;
            } else {
                odds -= 1;
            }
        }

        System.out.println(Math.min(get(1, 0, odds, evens), get(1, 1, odds, evens)));
    }

    int get(int curr, int prev, int odds, int evens) {
        if(odds < 0) {
            return 200;
        }
        if(evens < 0) {
            return 200;
        }
        if(curr == n + 1) {
            return 0;
        }

        if(dp[curr][prev][odds][evens] != -1) {
            return dp[curr][prev][odds][evens];
        }

        if(p[curr] == 0) {
            int res = (prev == 1 ? 1 : 0) + get(curr + 1, 0, odds, evens - 1);
            res = Math.min(res, (prev == 0 ? 1 : 0) + get(curr + 1, 1, odds - 1, evens));
            return dp[curr][prev][odds][evens] = res;
        }

        int v = (p[curr] - prev) % 2 == 0 ? 0 : 1;
        return dp[curr][prev][odds][evens] = v + get(curr + 1, p[curr] % 2, odds, evens);
    }
}

class SegmentTree {
    private final int size;
    private final long[] data;
    private final long[] lazy;
    private final BiFunction<Long, Long, Long> updateFunction;

    public SegmentTree(long[] array, BiFunction<Long, Long, Long> updateFunction) {
        size = array.length;
        data = new long[size * 4];
        lazy = new long[size * 4];
        this.updateFunction = updateFunction;
        init(array, 1, 0, size - 1);
    }

    private long init(long[] array, int node, int start, int end) {
        if (start == end) {
            return data[node] = array[start];
        }
        int mid = (start + end) / 2;
        return data[node] = updateFunction.apply(init(array, node * 2, start, mid), init(array, node * 2 + 1, mid + 1, end));
    }

    public void updateRange(int l, int r, long diff) {
        updateRange(1, 0, size - 1, l, r, diff);
    }

    private void updateRange(int node, int start, int end, int l, int r, long diff) {
        propagation(node, start, end);
        if (isOutOfRange(start, end, l, r)) return;
        if (isAllIn(start, end, l, r)) {
            lazy[node] += diff;
            propagation(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, diff);
        updateRange(node * 2 + 1, mid + 1, end, l, r, diff);
        data[node] = updateFunction.apply(data[node * 2], data[node * 2 + 1]);
    }

    public long get(int l, int r) {
        return get(1, 0, size - 1, l, r);
    }

    private long get(int node, int start, int end, int l, int r) {
        propagation(node, start, end);
        if (isOutOfRange(start, end, l, r)) return 0;
        if (isAllIn(start, end, l, r)) return data[node];
        int mid = (start + end) / 2;
        return updateFunction.apply(get(node * 2, start, mid, l, r), get(node * 2 + 1, mid + 1, end, l, r));
    }

    private void propagation(int node, int start, int end) {
        long v = lazy[node];
        data[node] = updateFunction.apply(data[node], (end - start + 1) * v);
        if (start != end) {
            lazy[node * 2] += v;
            lazy[node * 2 + 1] += v;
        }
        lazy[node] = 0;
    }

    private boolean isOutOfRange(int start, int end, int l, int r) {
        return l > end || r <= start;
    }

    private boolean isAllIn(int start, int end, int l, int r) {
        return l <= start && end < r;
    }
}

class MathUtil {

    public static List<Integer> getPrimes(int r) {
        if (r < 2) {
            return List.of();
        }

        List<Integer> result = new ArrayList<>();
        result.add(2);
        boolean[] is = new boolean[r + 1];
        for (int i = 4; i <= r; i += 2) {
            is[i] = true;
        }
        for (int i = 3; i <= r; i += 2) {
            if (is[i]) continue;
            result.add(i);
            for (long j = (long) i * i; j <= r; j += i) {
                is[(int) j] = true;
            }
        }
        return result;
    }

    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
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
    private int size;

    public DisjointSet(int size) {
        this.size = size;
        f = new int[size];
        for (int i = 0; i < size; i++) {
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

    public int getGroupCounts() {
        Set<Integer> groups = new HashSet<>();
        for (int i = 0; i < size; i++) {
            groups.add(find(i));
        }
        return groups.size();
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

class LongPair {
    private long l;
    private long r;

    public LongPair(long l, long r) {
        this.l = l;
        this.r = r;
    }

    public long getL() {
        return l;
    }

    public void setL(long l) {
        this.l = l;
    }

    public long getR() {
        return r;
    }

    public void setR(long r) {
        this.r = r;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        LongPair pair = (LongPair) o;
        return l == pair.l &&
                r == pair.r;
    }

    @Override
    public int hashCode() {
        return Objects.hash(l, r);
    }
}

class Parser {
    private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private StringTokenizer tokenizer;

    public int parseInt() {
        fill();
        return Integer.parseInt(tokenizer.nextToken());
    }

    public long parseLong() {
        fill();
        return java.lang.Long.parseLong(tokenizer.nextToken());
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