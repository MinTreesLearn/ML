import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.*;
import java.util.*;
import java.util.function.*;

public class E {

    private static final FastReader in = new FastReader();
    private static final FastWriter out = new FastWriter();

    public static void main(String[] args) {
        new E().run();
    }

    private void run() {
        var t = 1;
        while (t-- > 0) {
            solve();
        }

        out.flush();
    }

    private void solve() {
        var n = in.nextInt();
        var a = in.nextLongArray(n);

        var sum = new long[n + 1];
        sum[0] = 0;
        for (var i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i - 1];
        }

        var q = new int[n + 1];
        var top = 0;
        for (var i = 1; i <= n; i++) {
            while (top > 0) {
                var j = q[top];
                var k = q[top - 1];
                double topAvg = (double) (sum[j] - sum[k]) / (j - k);
                double nowAvg = (double) (sum[i] - sum[k]) / (i - k);
                if (EPS_COMPARATOR.compare(topAvg, nowAvg) >= 0) {
                    top--;
                } else {
                    break;
                }
            }

            q[++top] = i;
        }

        var ans = new double[n];
        for (var i = 1; i <= top; i++) {
            var j = q[i];
            var k = q[i - 1];
            double avg = (double) (sum[j] - sum[k]) / (j - k);
            for (var l = k + 1; l <= j; l++) {
                ans[l - 1] = avg;
            }
        }

        out.println(ans);
    }

    private static final double EPS = 1e-12;
    private static final Comparator<Double> EPS_COMPARATOR = (x, y) -> {
        if (x + EPS < y) {
            return -1;
        } else if (x - EPS > y) {
            return 1;
        } else {
            return 0;
        }
    };

    @SuppressWarnings("unused")
    private static int binarySearch(int left, int right, Predicate<Integer> leftShouldAdvance) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (leftShouldAdvance.test(mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    @SuppressWarnings("unused")
    private static class Pair<T, U> {

        T a;
        U b;

        Pair(T a, U b) {
            this.a = a;
            this.b = b;
        }

        static <T, U> Pair<T, U> of(T a, U b) {
            return new Pair<>(a, b);
        }

        T getA() {
            return a;
        }

        U getB() {
            return b;
        }

    }

    @SuppressWarnings("unused")
    private static class IntPair extends Pair<Integer, Integer> {

        IntPair(Integer a, Integer b) {
            super(a, b);
        }

        static IntPair of(int a, int b) {
            return new IntPair(a, b);
        }

    }

    @SuppressWarnings("unused")
    private static class Triple<T, U, V> {

        T a;
        U b;
        V c;

        Triple(T a, U b, V c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        T getA() {
            return a;
        }

        U getB() {
            return b;
        }

        V getC() {
            return c;
        }

    }

    @SuppressWarnings("unused")
    private static class IntTriple extends Triple<Integer, Integer, Integer> {

        IntTriple(Integer a, Integer b, Integer c) {
            super(a, b, c);
        }

    }

    @SuppressWarnings("unused")
    private static class FastReader {

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

    @SuppressWarnings("unused")
    private static class FastWriter extends PrintWriter {

        public FastWriter() {
            super(System.out);
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

        public <T> void println(T[] a) {
            for (var i = 0; i < a.length; i++) {
                print(a[i]);
                print(i + 1 < a.length ? ' ' : '\n');
            }
        }

        public void debug(String name, Object o) {
            String value = Arrays.deepToString(new Object[] { o });
            value = value.substring(1, value.length() - 1);
            System.err.println(name + " => " + value);
        }

    }

}
