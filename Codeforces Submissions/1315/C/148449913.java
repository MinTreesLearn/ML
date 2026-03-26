import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.in;
import static java.lang.System.out;

public class Restoring_Permutation {
    public static void main(String[] args) {
        try {
            FastReader in = new FastReader();
            FastWriter out = new FastWriter();
            int test = in.nextInt();
            while (test > 0) {
                //Your Code Here
                int n = in.nextInt();
                int[] array = new int[n];
                for (int i = 0; i < array.length; i++) {
                    array[i] = in.nextInt();
                }
                calc(n, array);
                test--;
            }
            out.close();
        } catch (Exception e) {
            return;
        }

    }

    private static void calc(int n, int[] array) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < array.length; i++) {
            list.add(array[i]);
            list.add(0);
        }
        for (int i = 0; i < 2 * n; i = i + 2) {
            int value = list.get(i) + 1;
            while (value <= 2 * n) {
                if (!list.contains(value)) {
                    list.set(i + 1, value);
                    break;
                } else {
                    value++;
                }
            }
        }
        boolean check = false;
        for (int i = 1; i <= 2 * n; i++) {
            if (!list.contains(i)) {
                check = true;
                break;
            }
        }
        if (check) {
            out.println(-1);
        } else {
            for (Integer i : list) {
                out.print(i + " ");
            }
            out.println("");
        }
    }

    static class FastWriter {
        private final BufferedWriter bw;

        public FastWriter() {
            this.bw = new BufferedWriter(new OutputStreamWriter(out));
        }

        public void print(Object object) throws IOException {
            bw.append("" + object);
        }

        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }

        public void close() throws IOException {
            bw.close();
        }
    }

    public static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return parseInt(next());
        }

        long nextLong() {
            return parseLong(next());
        }

        double nextDouble() {
            return parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }

}
