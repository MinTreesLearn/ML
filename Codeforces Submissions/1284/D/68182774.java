import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.function.LongBinaryOperator;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedOutputStream;
import java.io.UncheckedIOException;
import java.util.Objects;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        LightWriter out = new LightWriter(outputStream);
        DNewYearAndConference solver = new DNewYearAndConference();
        solver.solve(1, in, out);
        out.close();
    }

    static class DNewYearAndConference {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            out.setBoolLabel(LightWriter.BoolLabel.YES_NO_ALL_UP);
            int n = in.ints();
            DNewYearAndConference.Event[] events = new DNewYearAndConference.Event[n];
            for (int i = 0; i < n; i++)
                events[i] = new DNewYearAndConference.Event(in.longs(), in.longs(), in.longs(), in.longs());
            if (solve(n, events)) {
                out.noln();
                return;
            }
            for (int j = 0; j < n; j++) events[j].swap();
            if (solve(n, events)) {
                out.noln();
                return;
            }
            out.yesln();
        }

        static boolean solve(int n, DNewYearAndConference.Event[] events) {
            DNewYearAndConference.Event[] starts = events.clone(), ends = events.clone();
            IntroSort.sort(starts, Comparator.comparing(event -> event.s1));
            IntroSort.sort(ends, Comparator.comparing(event -> event.e1));

            for (int j = 0; j < n; j++) ends[j].index = j;

            IntSegmentTree min, max;
            {
                max = new IntSegmentTree(new long[n + 1], Math::max, -1, (x, u) -> u);
                long[] tmp = new long[n + 1];
                Arrays.fill(tmp, Long.MAX_VALUE);
                min = new IntSegmentTree(tmp, Math::min, Long.MAX_VALUE, (x, u) -> u);
            }

            int cur = 0;
            for (int i = 0; i < n; i++) {
                while (cur < n && starts[cur].s1 <= ends[i].e1) {
                    max.update(starts[cur].index, starts[cur].s2);
                    min.update(starts[cur].index, starts[cur].e2);
                    cur++;
                }

                int ok = 0, ng = n;
                while (ng - ok > 1) {
                    int mid = (ng + ok) / 2;
                    if (ends[i].s1 <= ends[mid].e1) ng = mid;
                    else ok = mid;
                }

                long maxStart = max.query(ng, n), minEnd = min.query(ng, n);
                if (ends[i].e2 < maxStart || minEnd < ends[i].s2) {
                    return true;
                }
            }
            return false;
        }

        private static class Event {
            long s1;
            long e1;
            long s2;
            long e2;
            int index;

            Event(long s1, long e1, long s2, long e2) {
                this.s1 = s1;
                this.e1 = e1;
                this.s2 = s2;
                this.e2 = e2;
            }

            void swap() {
                long t = s1;
                s1 = s2;
                s2 = t;

                t = e1;
                e1 = e2;
                e2 = t;
            }

            public String toString() {
                return "Event{" +
                        "s1=" + s1 +
                        ", e1=" + e1 +
                        ", s2=" + s2 +
                        ", e2=" + e2 +
                        ", index=" + index +
                        '}';
            }

        }

    }

    static class InsertionSort {
        private InsertionSort() {
        }

        static <T> void sort(T[] a, int low, int high, Comparator<? super T> comparator) {
            for (int i = low; i < high; i++) {
                for (int j = i; j > low && comparator.compare(a[j - 1], a[j]) > 0; j--) {
                    ArrayUtil.swap(a, j - 1, j);
                }
            }
        }

    }

    static class IntSegmentTree {
        private final int n;
        private final int m;
        private final long[] tree;
        private final LongBinaryOperator op;
        private final LongBinaryOperator up;
        private final long zero;

        public IntSegmentTree(long[] array, LongBinaryOperator op, long zero, LongBinaryOperator up) {
            this.n = array.length;
            int msb = BitMath.extractMsb(n);
            this.m = n == msb ? msb : (msb << 1);
            this.tree = new long[m * 2 - 1];
            this.op = op;
            this.up = up;
            this.zero = zero;
            Arrays.fill(tree, zero);
            System.arraycopy(array, 0, this.tree, m - 1, array.length);
            for (int i = m - 2; i >= 0; i--) {
                tree[i] = op.applyAsLong(tree[2 * i + 1], tree[2 * i + 2]);
            }
        }

        public void update(int i, long v) {
            i += m - 1;
            tree[i] = up.applyAsLong(tree[i], v);
            while (i > 0) {
                i = (i - 1) / 2;
                tree[i] = op.applyAsLong(tree[2 * i + 1], tree[2 * i + 2]);
            }
        }

        public long query(int l, int r) {
            long left = zero, right = zero;
            l += m - 1;
            r += m - 1;
            while (l < r) {
                if ((l & 1) == 0) {
                    left = op.applyAsLong(left, tree[l]);
                }
                if ((r & 1) == 0) {
                    right = op.applyAsLong(tree[r - 1], right);
                }
                l = l / 2;
                r = (r - 1) / 2;
            }
            return op.applyAsLong(left, right);
        }

    }

    static interface Verified {
    }

    static class QuickSort {
        private QuickSort() {
        }

        private static <T> void med(T[] a, int low, int x, int y, int z, Comparator<? super T> comparator) {
            if (comparator.compare(a[z], a[x]) < 0) {
                ArrayUtil.swap(a, low, x);
            } else if (comparator.compare(a[y], a[z]) < 0) {
                ArrayUtil.swap(a, low, y);
            } else {
                ArrayUtil.swap(a, low, z);
            }
        }

        static <T> int step(T[] a, int low, int high, Comparator<? super T> comparator) {
            int x = low + 1, y = low + (high - low) / 2, z = high - 1;
            if (comparator.compare(a[x], a[y]) < 0) {
                med(a, low, x, y, z, comparator);
            } else {
                med(a, low, y, x, z, comparator);
            }

            int lb = low + 1, ub = high;
            while (true) {
                while (comparator.compare(a[lb], a[low]) < 0) {
                    lb++;
                }
                ub--;
                while (comparator.compare(a[low], a[ub]) < 0) {
                    ub--;
                }
                if (lb >= ub) {
                    return lb;
                }
                ArrayUtil.swap(a, lb, ub);
                lb++;
            }
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

        public long longs() {
            return Long.parseLong(string());
        }

    }

    static class LightWriter implements AutoCloseable {
        private final Writer out;
        private boolean autoflush = false;
        private boolean breaked = true;
        private LightWriter.BoolLabel boolLabel = LightWriter.BoolLabel.YES_NO_FIRST_UP;

        public LightWriter(Writer out) {
            this.out = out;
        }

        public LightWriter(OutputStream out) {
            this(new OutputStreamWriter(new BufferedOutputStream(out), Charset.defaultCharset()));
        }

        public void setBoolLabel(LightWriter.BoolLabel label) {
            this.boolLabel = Objects.requireNonNull(label);
        }

        public LightWriter print(char c) {
            try {
                out.write(c);
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter print(String s) {
            try {
                out.write(s, 0, s.length());
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter ans(String s) {
            if (!breaked) {
                print(' ');
            }
            return print(s);
        }

        public LightWriter ans(boolean b) {
            return ans(boolLabel.transfer(b));
        }

        public LightWriter yesln() {
            return ans(true).ln();
        }

        public LightWriter noln() {
            return ans(false).ln();
        }

        public LightWriter ln() {
            print(System.lineSeparator());
            breaked = true;
            if (autoflush) {
                try {
                    out.flush();
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex);
                }
            }
            return this;
        }

        public void close() {
            try {
                out.close();
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

        public enum BoolLabel {
            YES_NO_FIRST_UP("Yes", "No"),
            YES_NO_ALL_UP("YES", "NO"),
            YES_NO_ALL_DOWN("yes", "no"),
            Y_N_ALL_UP("Y", "N"),
            POSSIBLE_IMPOSSIBLE_FIRST_UP("Possible", "Impossible"),
            POSSIBLE_IMPOSSIBLE_ALL_UP("POSSIBLE", "IMPOSSIBLE"),
            POSSIBLE_IMPOSSIBLE_ALL_DOWN("possible", "impossible"),
            FIRST_SECOND_FIRST_UP("First", "Second"),
            FIRST_SECOND_ALL_UP("FIRST", "SECOND"),
            FIRST_SECOND_ALL_DOWN("first", "second"),
            ALICE_BOB_FIRST_UP("Alice", "Bob"),
            ALICE_BOB_ALL_UP("ALICE", "BOB"),
            ALICE_BOB_ALL_DOWN("alice", "bob"),
            ;
            private final String positive;
            private final String negative;

            BoolLabel(String positive, String negative) {
                this.positive = positive;
                this.negative = negative;
            }

            private String transfer(boolean f) {
                return f ? positive : negative;
            }

        }

    }

    static class IntroSort {
        private static int INSERTIONSORT_THRESHOLD = 16;

        private IntroSort() {
        }

        static <T> void sort(T[] a, int low, int high, int maxDepth, Comparator<T> comparator) {
            while (high - low > INSERTIONSORT_THRESHOLD) {
                if (maxDepth-- == 0) {
                    HeapSort.sort(a, low, high, comparator);
                    return;
                }
                int cut = QuickSort.step(a, low, high, comparator);
                sort(a, cut, high, maxDepth, comparator);
                high = cut;
            }
            InsertionSort.sort(a, low, high, comparator);
        }

        public static <T> void sort(T[] a, Comparator<T> comparator) {
            if (a.length <= INSERTIONSORT_THRESHOLD) {
                InsertionSort.sort(a, 0, a.length, comparator);
            } else {
                sort(a, 0, a.length, 2 * BitMath.msb(a.length), comparator);
            }
        }

    }

    static final class BitMath {
        private BitMath() {
        }

        public static int count(int v) {
            v = (v & 0x55555555) + ((v >> 1) & 0x55555555);
            v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
            v = (v & 0x0f0f0f0f) + ((v >> 4) & 0x0f0f0f0f);
            v = (v & 0x00ff00ff) + ((v >> 8) & 0x00ff00ff);
            v = (v & 0x0000ffff) + ((v >> 16) & 0x0000ffff);
            return v;
        }

        public static int msb(int v) {
            if (v == 0) {
                throw new IllegalArgumentException("Bit not found");
            }
            v |= (v >> 1);
            v |= (v >> 2);
            v |= (v >> 4);
            v |= (v >> 8);
            v |= (v >> 16);
            return count(v) - 1;
        }

        public static int extractMsb(int v) {
            v = (v & 0xFFFF0000) > 0 ? v & 0xFFFF0000 : v;
            v = (v & 0xFF00FF00) > 0 ? v & 0xFF00FF00 : v;
            v = (v & 0xF0F0F0F0) > 0 ? v & 0xF0F0F0F0 : v;
            v = (v & 0xCCCCCCCC) > 0 ? v & 0xCCCCCCCC : v;
            v = (v & 0xAAAAAAAA) > 0 ? v & 0xAAAAAAAA : v;
            return v;
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static <T> void swap(T[] a, int x, int y) {
            T t = a[x];
            a[x] = a[y];
            a[y] = t;
        }

    }

    static class HeapSort {
        private HeapSort() {
        }

        private static <T> void heapfy(T[] a, int low, int high, int i, T val, Comparator<? super T> comparator) {
            int child = 2 * i - low + 1;
            while (child < high) {
                if (child + 1 < high && comparator.compare(a[child], a[child + 1]) < 0) {
                    child++;
                }
                if (comparator.compare(val, a[child]) >= 0) {
                    break;
                }
                a[i] = a[child];
                i = child;
                child = 2 * i - low + 1;
            }
            a[i] = val;
        }

        static <T> void sort(T[] a, int low, int high, Comparator<T> comparator) {
            for (int p = (high + low) / 2 - 1; p >= low; p--) {
                heapfy(a, low, high, p, a[p], comparator);
            }
            while (high > low) {
                high--;
                T pval = a[high];
                a[high] = a[low];
                heapfy(a, low, high, low, pval, comparator);
            }
        }

    }
}

