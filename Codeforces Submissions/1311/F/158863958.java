import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Objects;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        FMovingPoints solver = new FMovingPoints();
        solver.solve(1, in, out);
        out.close();
    }

    static class FMovingPoints {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] x = in.nextIntArray(n);
            int[] s = in.nextIntArray(n);
            int mx = Integer.MAX_VALUE;
            int ms = Integer.MAX_VALUE;
            for (int a : x) mx = Math.min(mx, a);
            s = compress(s);
            ArrayList<Pair> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                x[i] -= mx;

                list.add(new Pair(x[i], s[i]));
            }
            Collections.sort(list);
            for (int i = 0; i < n; i++) {
                x[i] = list.get(i).a;
                s[i] = list.get(i).b;
            }
//        out.println(x);
//        out.println(s);
            long ans = 0;
            FenwickTree f = new FenwickTree(200005);
            FenwickTree freq = new FenwickTree(200005);


            for (int i = n - 1; i >= 0; i--) {

                ans += f.find(s[i], 200002);
                long count = freq.find(s[i], 200002);
                ans -= (long) x[i] * count;
//            d.dbg(ans,f.find(s[i],100002),freq.find(s[i],100002));
//            d.dbg(ans,i,s[i],f.find(s[i]+1,100002));
                if (i == 0) break;
//            d.dbg(i,f.find(s[i]),x[i],s[i]);
                f.add(s[i], x[i]);

                freq.add(s[i], 1);
//            d.dbg(freq.find(s[i],s[i]),s[i]);
            }
            out.println(ans);
        }

        int[] compress(int[] arr) {
            ArrayList<Integer> ls = new ArrayList<Integer>();
            for (int x : arr)
                ls.add(x);
            Collections.sort(ls);
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            int boof = 1; //min value
            for (int x : ls)
                if (!map.containsKey(x))
                    map.put(x, boof++);
            int[] brr = new int[arr.length];
            for (int i = 0; i < arr.length; i++)
                brr[i] = map.get(arr[i]);
            return brr;
        }

        class Pair implements Comparable<Pair> {
            int a;
            int b;

            Pair(int a, int b) {
                this.a = a;
                this.b = b;
            }

            public int hashCode() {
                return Objects.hash(a, b);
            }

            public boolean equals(Object obj) {
                Pair that = (Pair) obj;
                return a == that.a && b == that.b;
            }

            public String toString() {
                return "[" + a + ", " + b + "]";
            }

            public int compareTo(Pair v) {
                return a - v.a;
            }

        }

        class FenwickTree {
            public long[] tree;
            public int size;

            public FenwickTree(int size) {
                this.size = size;
                tree = new long[size + 5];
            }

            public void add(int i, long v) {
                while (i <= size) {
                    tree[i] += v;
                    i += i & -i;
                }
            }

            public long find(int i) {
                long res = 0;
                while (i >= 1) {
                    res += tree[i];
                    i -= i & -i;
                }
                return res;
            }

            public long find(int l, int r) {
                return find(r) - find(l - 1);
            }

        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

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

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}

