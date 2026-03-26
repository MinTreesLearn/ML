import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
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
        int m = parser.parseInt();

        List<List<Integer>> edges = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            edges.add(new ArrayList<>());
        }
        for(int i = 0; i < m; i++) {
            int a = parser.parseInt();
            int b = parser.parseInt();

            List<Integer> bEdge = edges.get(b);
            bEdge.add(a);
        }

        int k = parser.parseInt();
        int[] p = new int[k];
        for(int i = 0; i < k; i++) {
            p[i] = parser.parseInt();
        }

        int[] counts = new int[n + 1];
        int[] dists = new int[n + 1];
        for(int i = 0; i <= n; i++) {
            dists[i] = 0x3c3c3c3c;
        }

        Set<Integer> visited = new HashSet<>();
        Queue<IntPair> queue = new ArrayDeque<>();
        int start = p[k - 1];
        dists[start] = 0;
        counts[start] = 1;
        visited.add(start);
        queue.add(new IntPair(start, 0));
        while(!queue.isEmpty()) {
            int len = queue.size();
            for(int i = 0; i < len; i++) {
                IntPair intPair = queue.poll();
                int curr = intPair.getL();
                int dist = intPair.getR();

                for(int next : edges.get(curr)) {
                    if(dist + 1 < dists[next]) {
                        dists[next] = dist + 1;
                        counts[next] = 1;
                    } else if(dist + 1 == dists[next]) {
                        counts[next] += 1;
                    }
                    if(!visited.contains(next)) {
                        visited.add(next);
                        queue.add(new IntPair(next, dist + 1));
                    }
                }
            }
        }

        int minV = 0;
        int maxV = 0;
        for(int i = 0; i < k - 1; i++) {
            int curr = p[i];
            int next = p[i + 1];
            if(dists[curr] - 1 < dists[next]) {
                minV += 1;
                maxV += 1;
            } else if(dists[curr] - 1 == dists[next] && counts[curr] >= 2) {
                maxV += 1;
            }
        }

        System.out.println(minV + " " + maxV);
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