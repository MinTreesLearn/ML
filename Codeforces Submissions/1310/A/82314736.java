import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * @author Nikita Gorokhov <wackloner@yandex-team.ru>
 */
public class A1310 {

    // 420 remainder: use long everywhere

    private final static boolean MULTIPLE_TESTS = false;

    private FastReader reader;
    private FastWriter writer;

    private void solve() {
        int n = reader.readInt();
        int[] a = reader.readIntArray(n);
        int[] t = reader.readIntArray(n);

        var sorted = IntStream.range(0, n)
                .mapToObj(i -> Tuple.Tuple2.of(a[i], t[i]))
                .sorted()
                .collect(Collectors.toList());

        TreeMap<Integer, Integer> multiset = new TreeMap<>();
        long sumInSet = 0;
        long ans = 0;
        int last = -1;
        for (int i = 0; i < n; i++) {
            var cur = sorted.get(i);

            if (cur.first != last) {
                while (!multiset.isEmpty() && last < cur.first) {
                    var max = multiset.lastEntry();
                    var newVal = max.getValue() - 1;
                    sumInSet -= max.getKey();
                    if (newVal == 0) {
                        multiset.remove(max.getKey());
                    } else {
                        multiset.put(max.getKey(), max.getValue() - 1);
                    }
                    ans += sumInSet;
                    last++;
                }

                last = cur.first;
            }

            multiset.put(cur.second, multiset.getOrDefault(cur.second, 0) + 1);
            sumInSet += cur.second;
        }

        while (!multiset.isEmpty()) {
            var max = multiset.lastEntry();
            var newVal = max.getValue() - 1;
            sumInSet -= max.getKey();
            if (newVal == 0) {
                multiset.remove(max.getKey());
            } else {
                multiset.put(max.getKey(), max.getValue() - 1);
            }
            ans += sumInSet;
            last++;
        }

        writer.print(ans);
    }

    private void run() throws Exception {
        reader = new FastReader();
        writer = new FastWriter();

        int t = MULTIPLE_TESTS ? reader.readInt() : 1;

        for (int testNum = 0; testNum < t; testNum++) {
            solve();
        }

        writer.close();
        reader.close();
    }

    public static void main(String[] args) throws Exception {
        new A1310().run();
    }

    private final static boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

    private static class FastWriter implements AutoCloseable {
        @SuppressWarnings(value="all")
        private final static Optional<String> OUTPUT_FILENAME = Optional.empty();

        private final PrintWriter out;

        public FastWriter() throws FileNotFoundException {
            this.out = OUTPUT_FILENAME.isEmpty() ? new PrintWriter(System.out) : new PrintWriter(new File(OUTPUT_FILENAME.get()));
        }

        public void print(int value) {
            out.print(value);
        }

        public void print(long value) {
            out.print(value);
        }

        public void print(double value) {
            out.print(value);
        }

        public <T> void print(T value) {
            out.print(value);
        }

        public void println(int value) {
            out.println(value);
        }

        public void println(long value) {
            out.println(value);
        }

        public void println(double value) {
            out.println(value);
        }

        public <T> void println(T value) {
            out.println(value);
        }

        public <T> void printArray(T[] array) {
            for (int i = 0; i < array.length; i++) {
                out.print(array[i]);
                if (i + 1 < array.length) {
                    out.print(' ');
                }
            }
            out.println();
        }

        public void printArray(int[] array) {
            for (int i = 0; i < array.length; i++) {
                out.print(array[i]);
                if (i + 1 < array.length) {
                    out.print(' ');
                }
            }
            out.println();
        }

        public void printArray(long[] array) {
            for (int i = 0; i < array.length; i++) {
                out.print(array[i]);
                if (i + 1 < array.length) {
                    out.print(' ');
                }
            }
            out.println();
        }

        public void printArray(double[] array) {
            for (int i = 0; i < array.length; i++) {
                out.print(array[i]);
                if (i + 1 < array.length) {
                    out.print(' ');
                }
            }
            out.println();
        }

        @Override
        public void close() {
            out.close();
        }
    }

    private static class FastReader implements AutoCloseable {
        private final static String INPUT_FILENAME = "input.txt";

        private final InputStream inputStream;
        private final byte[] buffer = new byte[1024];

        private int bufferLen = 0;
        private int bufferPtr = 0;

        public FastReader() throws FileNotFoundException {
            this.inputStream = ONLINE_JUDGE ? System.in : new FileInputStream(INPUT_FILENAME);
        }

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public long[] readLongArray(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public double[] readDoubleArray(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public double readDouble() {
            return Double.parseDouble(readToken());
        }

        public String readToken() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public int readInt() {
            int num = 0, b;
            boolean minus = false;

            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));

            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        public long readLong() {
            long num = 0;
            int b;
            boolean minus = false;

            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));

            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        public int readByte() {
            if (bufferLen == -1) {
                throw new InputMismatchException();
            }
            if (bufferPtr >= bufferLen) {
                bufferPtr = 0;
                try {
                    bufferLen = inputStream.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (bufferLen <= 0) {
                    return -1;
                }
            }
            return buffer[bufferPtr++];
        }

        public char readChar() {
            return (char) skip();
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b));
            return b;
        }

        private static boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        @Override
        public void close() throws Exception {
            inputStream.close();
            bufferPtr = bufferLen;
        }
    }

    private static class Tuple {
        public static <A, B> Tuple2<A, B> of(A first, B second) {
            return new Tuple2<>(first, second);
        }

        public static <A extends Comparable<A>, B extends Comparable<B>> Tuple2<A, B> of(A first, B second) {
            return new ComparableTuple2<>(first, second);
        }

        public static <A, B, C> Tuple3<A, B, C> of(A first, B second, C third) {
            return new Tuple3<>(first, second, third);
        }

        public static <A extends Comparable<A>, B extends Comparable<B>, C extends Comparable<C>> Tuple3<A, B, C> of(A first, B second, C third) {
            return new ComparableTuple3<>(first, second, third);
        }

        private static class Tuple2<A, B> extends Tuple {
            public final A first;
            public final B second;

            private Tuple2(A first, B second) {
                this.first = first;
                this.second = second;
            }

            @Override
            public String toString() {
                return "(" + first + ", " + second + ")";
            }
        }

        private static class Tuple3<A, B, C> extends Tuple2<A, B> {
            public final C third;

            private Tuple3(A first, B second, C third) {
                super(first, second);
                this.third = third;
            }

            @Override
            public String toString() {
                return "(" + first + ", " + second + ", " + third + ")";
            }
        }

        private static class ComparableTuple2<A extends Comparable<A>, B extends Comparable<B>> extends Tuple2<A, B> implements Comparable<ComparableTuple2<A, B>> {
            private ComparableTuple2(A first, B second) {
                super(first, second);
            }

            @Override
            @SuppressWarnings("unchecked")
            public int compareTo(ComparableTuple2 that) {
                var res = first.compareTo((A) that.first);
                return res == 0 ? second.compareTo((B) that.second) : res;
            }
        }

        private static class ComparableTuple3<A extends Comparable<A>, B extends Comparable<B>, C extends Comparable<C>>
                extends Tuple3<A, B, C> implements Comparable<ComparableTuple3<A, B, C>> {

            private ComparableTuple3(A first, B second, C third) {
                super(first, second, third);
            }

            @Override
            @SuppressWarnings("unchecked")
            public int compareTo(ComparableTuple3 that) {
                var firstR = first.compareTo((A) that.first);
                if (firstR == 0) {
                    var secondR = second.compareTo((B) that.second);
                    if (secondR == 0) {
                        return third.compareTo((C) that.third);
                    }
                    return secondR;
                }
                return firstR;
            }
        }
    }

    private static class Utils {
        private static final Random random = new Random(System.nanoTime());

        public static <T extends Comparable<T>> void sort(T[] array) {
            shuffle(array);
            Arrays.sort(array);
        }

        public static void sort(int[] array) {
            shuffle(array);
            Arrays.sort(array);
        }

        public static void sort(long[] array) {
            shuffle(array);
            Arrays.sort(array);
        }

        public static void sort(double[] array) {
            shuffle(array);
            Arrays.sort(array);
        }

        public static <T> void sort(T[] array, Comparator<T> comparator) {
            shuffle(array);
            Arrays.sort(array, comparator);
        }

        public static <T> void shuffle(T[] array) {
            for (int i = array.length - 1; i > 0; i--) {
                int index = random.nextInt(i + 1);
                T a = array[index];
                array[index] = array[i];
                array[i] = a;
            }
        }

        public static void shuffle(int[] array) {
            for (int i = array.length - 1; i > 0; i--) {
                int index = random.nextInt(i + 1);
                int a = array[index];
                array[index] = array[i];
                array[i] = a;
            }
        }

        public static void shuffle(long[] array) {
            for (int i = array.length - 1; i > 0; i--) {
                int index = random.nextInt(i + 1);
                long a = array[index];
                array[index] = array[i];
                array[i] = a;
            }
        }

        public static void shuffle(double[] array) {
            for (int i = array.length - 1; i > 0; i--) {
                int index = random.nextInt(i + 1);
                double a = array[index];
                array[index] = array[i];
                array[i] = a;
            }
        }

        public static <T extends Comparable<T>> void sort(List<T> list) {
            Collections.shuffle(list);
            Collections.sort(list);
        }

        public static <T> void sort(List<T> list, Comparator<T> comparator) {
            Collections.shuffle(list);
            list.sort(comparator);
        }

        public static int randomInt(int fromIncluded, int toExcluded) {
            return fromIncluded + random.nextInt(toExcluded - fromIncluded);
        }
    }
}
