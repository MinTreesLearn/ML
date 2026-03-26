import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Objects;
import java.util.StringTokenizer;
import java.util.function.IntConsumer;
import java.util.stream.Collectors;
import java.util.stream.IntStream;



public class F {

    private static final FastReader in = new FastReader();
    private static final FastWriter out = new FastWriter();

    public static void main(String[] args) {
        new F().run();
    }

    private void run() {
        var t = 1;
        while (t-- > 0) {
            solve();
        }

        out.flush();
    }

    private Tree<?> tree;
    private LCA lca;
    private int[] w;

    private void solve() {
        var n = in.nextInt();

        var g = Graph.unweighted(n);

        var edges = new ArrayList<IntPair>(n - 1);
        for (var i = 1; i < n; i++) {
            var u = in.nextInt() - 1;
            var v = in.nextInt() - 1;
            g.addBidirectedEdges(u, v);
            edges.add(IntPair.of(u, v));
        }
        tree = g.asTree(0);
        lca = new LCA(tree);

        var m = in.nextInt();
        var queries = new ArrayList<IntTriple>();
        for (var i = 0; i < m; i++) {
            var q = IntTriple.of(in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
            queries.add(q);
        }

        queries.sort(Comparator.comparing(IntTriple::getC).reversed());

        w = new int[n];
        for (var q : queries) {
            if (!mark(q)) {
                out.println(-1);
                return ;
            }
        }

        var f = edges.stream()
            .mapToInt(e -> {
                var u = e.a;
                var v = e.b;
                if (tree.parents[u] == v) {
                    var t = u;
                    u = v;
                    v = t;
                }

                return w[v] > 0 ? w[v] : 1;
            })
        .toArray();

        out.println(f);
    }

    boolean mark(IntTriple q) {
        boolean valid = false;
        int ancestor = lca.query(q.a, q.b);

        int u = q.a;
        while (u != ancestor) {
            if (w[u] == 0) {
                w[u] = q.c;
            }

            valid |= w[u] == q.c;
            u = tree.parents[u];
        }

        int v = q.b;
        while (v != ancestor) {
            if (w[v] == 0) {
                w[v] = q.c;
            }

            valid |= w[v] == q.c;
            v = tree.parents[v];
        }

        return valid;
    }

}


class FastReader {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer in;

    public String next() {
        while (in == null || !in.hasMoreTokens()) {
            try {
                in = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                return null;
            }
        }
        return in.nextToken();
    }

    public BigDecimal nextBigDecimal() {
        return new BigDecimal(next());
    }

    public BigInteger nextBigInteger() {
        return new BigInteger(next());
    }

    public boolean nextBoolean() {
        return Boolean.valueOf(next());
    }

    public byte nextByte() {
        return Byte.valueOf(next());
    }

    public double nextDouble() {
        return Double.valueOf(next());
    }

    public double[] nextDoubleArray(int length) {
        var a = new double[length];
        for (var i = 0; i < length; i++) {
            a[i] = nextDouble();
        }
        return a;
    }

    public int nextInt() {
        return Integer.valueOf(next());
    }

    public int[] nextIntArray(int length) {
        var a = new int[length];
        for (var i = 0; i < length; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    public long nextLong() {
        return Long.valueOf(next());
    }

    public long[] nextLongArray(int length) {
        var a = new long[length];
        for (var i = 0; i < length; i++) {
            a[i] = nextLong();
        }
        return a;
    }

}


class FastWriter extends PrintWriter {

    public FastWriter() {
        super(System.out);
    }

    public void println(boolean[] a) {
        for (var i = 0; i < a.length; i++) {
            print(a[i]);
            print(i + 1 < a.length ? ' ' : '\n');
        }
    }

    public void println(double[] a) {
        for (var i = 0; i < a.length; i++) {
            print(a[i]);
            print(i + 1 < a.length ? ' ' : '\n');
        }
    }

    public void println(int[] a) {
        for (var i = 0; i < a.length; i++) {
            print(a[i]);
            print(i + 1 < a.length ? ' ' : '\n');
        }
    }

    public void println(long[] a) {
        for (var i = 0; i < a.length; i++) {
            print(a[i]);
            print(i + 1 < a.length ? ' ' : '\n');
        }
    }

    public void println(Object... a) {
        for (var i = 0; i < a.length; i++) {
            print(a[i]);
            print(i + 1 < a.length ? ' ' : '\n');
        }
    }

    public <T> void println(List<T> l) {
        println(l.toArray());
    }

    public void debug(String name, Object o) {
        String value = Arrays.deepToString(new Object[] { o });
        value = value.substring(1, value.length() - 1);
        System.err.println(name + " => " + value);
    }

}



abstract class Graph<T> {

    public final int n;
    final List<List<T>> adjacencyList;

    Graph(int n) {
        this.n = n;
        this.adjacencyList = new ArrayList<>(n);

        for (var i = 0; i < n; i++) {
            this.adjacencyList.add(new ArrayList<>());
        }
    }

    public static UnweightedGraph unweighted(int n) {
        return new UnweightedGraph(n);
    }

    public static <T> WeightedGraph<T> weighted(int n) {
        return new WeightedGraph<>(n);
    }

    public List<T> neighbors(int u) {
        return adjacencyList.get(u);
    }

    public abstract int neighborId(T neighbor);

    public int degree(int u) {
        return neighbors(u).size();
    }

    public Tree<T> asTree(int root) {
        return new Tree<>(this, root);
    }

    @Override
    public String toString() {
        String adj = IntStream.range(0, n)
                .mapToObj(i -> "    " + i + ": " + neighbors(i))
                .collect(Collectors.joining(",\n"));
        return "Graph {\n"
                + "  nodeCount: " + n + ",\n"
                + "  adjacencyList: {\n"
                + adj + "\n"
                + "  }\n"
                + "}";
    }

    public static class UnweightedGraph extends Graph<Integer> {

        UnweightedGraph(int n) {
            super(n);
        }

        public void addEdge(int u, int v) {
            adjacencyList.get(u).add(v);
        }

        public void addBidirectedEdges(int u, int v) {
            addEdge(u, v);
            addEdge(v, u);
        }


        @Override
        public int neighborId(Integer neighbor) {
            return neighbor;
        }

    }

    public static class WeightedGraph<T> extends Graph<Edge<T>> {

        WeightedGraph(int n) {
            super(n);
        }

        public void addEdge(int u, int v, T w) {
            adjacencyList.get(u).add(Edge.of(v, w));
        }

        public void addBidirectedEdges(int u, int v, T w) {
            addEdge(u, v, w);
            addEdge(v, u, w);
        }

        @Override
        public int neighborId(Edge<T> neighbor) {
            return neighbor.v;
        }

    }

    public static class Edge<T> {

        public final int v;
        public final T w;

        public Edge(int v, T w) {
            this.v = v;
            this.w = w;
        }

        public static <T> Edge<T> of(int v, T w) {
            return new Edge<>(v, w);
        }

        public int getV() {
            return v;
        }

        public T getW() {
            return w;
        }

        @Override
        public String toString() {
            return String.format("(%s, %s)", v, w);
        }

    }

}


class IntPair extends Pair<Integer, Integer> {

    IntPair(Integer a, Integer b) {
        super(a, b);
    }

    public static IntPair of(int a, int b) {
        return new IntPair(a, b);
    }

}


class IntTriple extends Triple<Integer, Integer, Integer> {

    IntTriple(Integer a, Integer b, Integer c) {
        super(a, b, c);
    }

    public static IntTriple of(int a, int b, int c) {
        return new IntTriple(a, b, c);
    }

}



class LCA {

    private final Tree<?> tree;
    private final RMQ<Integer> rmq;

    public LCA(Tree<?> tree) {
        this.tree = tree.savePreOrderIds().saveEulerTour().build();
        this.rmq = new RMQ<>(tree.eulerTour, Comparator.comparing(u -> tree.preOrderIds[u]));
    }

    public int query(int x, int y) {
        var l = tree.firstSeenInEulerTour[x];
        var r = tree.firstSeenInEulerTour[y];
        if (l > r) {
            var t = l;
            l = r;
            r = t;
        }

        return rmq.query(l, r + 1);
    }

}



class Tree<T> {

    public final Graph<T> graph;
    public final int n;
    public final int root;
    public int[] parents;
    public int[] depths;
    public int[] subTreeSizes;

    public int[] preOrderIds;
    private int currentPreOrderId;

    public int[] firstSeenInEulerTour;
    public List<Integer> eulerTour;

    public Tree(Graph<T> graph, int root) {
        this.graph = graph;
        this.n = graph.n;
        this.root = root;
        this.parents = new int[n];
    }

    public Tree<T> saveDepth() {
        this.depths = new int[n];
        return this;
    }

    public Tree<T> saveSubTreeSize() {
        this.subTreeSizes = new int[n];
        return this;
    }

    public Tree<T> savePreOrderIds() {
        this.preOrderIds = new int[n];
        return this;
    }

    public Tree<T> saveEulerTour() {
        this.firstSeenInEulerTour = new int[n];
        this.eulerTour = new ArrayList<>(n * 2 - 1);
        return this;
    }

    public Tree<T> build() {
        dfs(root, -1, 0);
        return this;
    }

    private void dfs(int u, int parent, int depth) {
        parents[u] = parent;

        if (preOrderIds != null) {
            preOrderIds[u] = currentPreOrderId++;
        }

        if (eulerTour != null) {
            firstSeenInEulerTour[u] = eulerTour.size();
            eulerTour.add(u);
        }

        forEachChild(u, v -> {
            dfs(v, u, depth + 1);

            if (eulerTour != null) {
                eulerTour.add(u);
            }
        });

        if (depths != null) {
            depths[u] = depth;
        }

        if (subTreeSizes != null) {
            subTreeSizes[u] = 1;
            forEachChild(u, v -> subTreeSizes[u] += subTreeSizes[v]);
        }
    }

    public void forEachChild(int u, IntConsumer consumer) {
        for (var neighbor : graph.neighbors(u)) {
            var v = graph.neighborId(neighbor);
            if (v != parents[u]) {
                consumer.accept(v);
            }
        }
    }

    public boolean isLeaf(int u) {
        return u == root ? false : graph.neighbors(u).size() == 1;
    }

}


class RMQ<T extends Comparable<T>> {

    private final int n;
    private final List<T> values;
    private final Comparator<T> comparator;
    private final int[][] ranges;

    public RMQ(List<T> values) {
        this(values, Comparator.naturalOrder());
    }

    public RMQ(List<T> values, Comparator<T> comparator) {
        this.values = values;
        this.comparator = comparator;
        this.n = values.size();
        this.ranges = new int[leftMostOneBit(n) + 1][];

        build();
    }

    private int leftMostOneBit(int x) {
        return Integer.SIZE - 1 - Integer.numberOfLeadingZeros(x);
    }

    private void build() {
        ranges[0] = new int[n];
        for (var i = 0; i < n; i++) {
            ranges[0][i] = i;
        }

        for (var i = 1; 1 << i <= n; i++) {
            ranges[i] = new int[n - (1 << i) + 1];
            for (var j = 0; j + (1 << i) <= n; j++) {
                ranges[i][j] = betterIndex(ranges[i - 1][j], ranges[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    private int betterIndex(int l, int r) {
        return comparator.compare(values.get(l), values.get(r)) < 0 ? l : r;
    }

    public int queryIndex(int l, int r) {
        var exponent = leftMostOneBit(r - l);
        return betterIndex(ranges[exponent][l], ranges[exponent][r - (1 << exponent)]);
    }

    public T query(int l, int r) {
        return values.get(queryIndex(l, r));
    }

}


class Triple<T, U, V> {

    public T a;
    public U b;
    public V c;

    Triple(T a, U b, V c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public static <T, U, V> Triple<T, U, V> of(T a, U b, V c) {
        return new Triple<>(a, b, c);
    }

    public T getA() {
        return a;
    }

    public U getB() {
        return b;
    }

    public V getC() {
        return c;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (!(obj instanceof Triple)) return false;

        var other = (Triple<?, ?, ?>) obj;
        return Objects.equals(a, other.a) && Objects.equals(b, other.b) && Objects.equals(c, other.c);
    }

    @Override
    public String toString() {
        return String.format("(%s, %s, %s)", a, b, c);
    }

}


class Pair<T, U> {

    public T a;
    public U b;

    Pair(T a, U b) {
        this.a = a;
        this.b = b;
    }

    public static <T, U> Pair<T, U> of(T a, U b) {
        return new Pair<>(a, b);
    }

    public T getA() {
        return a;
    }

    public U getB() {
        return b;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (!(obj instanceof Pair)) return false;

        var other = (Pair<?, ?>) obj;
        return Objects.equals(a, other.a) && Objects.equals(b, other.b);
    }

    @Override
    public String toString() {
        return String.format("(%s, %s)", a, b);
    }

}
