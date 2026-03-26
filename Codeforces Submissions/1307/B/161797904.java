import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class CowAndFriend {

    public static void main(String[] args) {
        MyScanner scanner = new MyScanner();
        int testCases = scanner.nextInt();

        for (int i = 0; i < testCases; i++) {
            int n = scanner.nextInt();
            double x = scanner.nextDouble();

            List<Double> lines = getDoubleList(n, scanner);
            lines.sort(Collections.reverseOrder());

            if (lines.contains(x)) {
                System.out.println("1");
            } else {
                int minCount = lines.get(0) >= (x / 2) ? 2 : (int) Math.ceil(x / lines.get(0));
                System.out.println(minCount);
            }
        }
    }


    /****** UTILITY *******/

    static class Vector2D {
        final double x;
        final double y;

        public Vector2D(double x, double y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            Vector2D vector = (Vector2D) o;
            return x == vector.x && y == vector.y;
        }

        @Override
        public int hashCode() {
            return (int) (31 * (31 * x + y));
        }
    }

    static List<Vector2D> getVectors(int n, MyScanner scanner) {
        final List<Vector2D> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new Vector2D(scanner.nextDouble(), scanner.nextDouble()));
        }
        return list;
    }

    static double distance(Vector2D a, Vector2D b) {
        return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
    }

    static double manhattanDistance(Vector2D a, Vector2D b) {
        return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
    }

    static Vector2D plus(Vector2D a, Vector2D b) {
        return new Vector2D(a.x + b.x, a.y + b.y);
    }

    static Vector2D minus(Vector2D a, Vector2D b) {
        return new Vector2D(a.x - b.x, a.y - b.y);
    }

    static Vector2D scalar(Vector2D v, double alpha) {
        return new Vector2D(alpha * v.x, alpha * v.y);
    }

    static List<String> getStringList(int n, MyScanner scanner) {
        final List<String> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(scanner.next());
        }
        return list;
    }

    static List<String[]> getStringArrays(int n, int m, MyScanner scanner) {
        final List<String[]> arrays = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] array = new String[m];
            for (int j = 0; j < m; j++) {
                array[j] = scanner.next();
            }
            arrays.add(array);
        }
        return arrays;
    }

    static List<Long> getLongList(int n, MyScanner scanner) {
        final List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(scanner.nextLong());
        }
        return list;
    }

    static List<long[]> getLongArrays(int n, int m, MyScanner scanner) {
        final List<long[]> arrays = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            long[] array = new long[m];
            for (int j = 0; j < m; j++) {
                array[j] = scanner.nextLong();
            }
            arrays.add(array);
        }
        return arrays;
    }

    static List<Integer> getIntList(int n, MyScanner scanner) {
        final List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }
        return list;
    }

    static List<int[]> getIntArrays(int n, int m, MyScanner scanner) {
        final List<int[]> arrays = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int[] array = new int[m];
            for (int j = 0; j < m; j++) {
                array[j] = scanner.nextInt();
            }
            arrays.add(array);
        }
        return arrays;
    }

    static List<Double> getDoubleList(int n, MyScanner scanner) {
        final List<Double> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(scanner.nextDouble());
        }
        return list;
    }

    static List<double[]> getDoubleArrays(int n, int m, MyScanner scanner) {
        final List<double[]> arrays = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            double[] array = new double[m];
            for (int j = 0; j < m; j++) {
                array[j] = scanner.nextDouble();
            }
            arrays.add(array);
        }
        return arrays;
    }

    private static class MyScanner {

        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
