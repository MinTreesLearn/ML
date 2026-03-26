import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.in;
import static java.lang.System.out;

public class Journey_Planning {
    public static void main(String[] args) {
        try {
            FastReader in = new FastReader();
            FastWriter out = new FastWriter();
            int n = in.nextInt();
            ArrayList<Integer> array = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                array.add(in.nextInt());
            }
            calc(n, array);
            out.close();
        } catch (Exception e) {
            return;
        }

    }

    private static void calc(int n, ArrayList<Integer> array) {
        long max = 0;
        HashMap<Integer, Long> map = new HashMap();
        for (int i = 0; i < n; i++) {
            int temp = array.get(i) - i;
            map.put(temp, map.getOrDefault(temp, 0l) + array.get(i));
            max = Math.max(max, map.get(temp));
        }
        out.println(max);

    }

    private static long gcd(long a, long b) {
        if (a == 0) {
            return b;
        } else {
            return (gcd(b % a, a));
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
