import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.in;
import static java.lang.System.out;

public class Kuroni_and_Simple_Strings {
    public static void main(String[] args) {
        try {
            FastReader in = new FastReader();
            FastWriter out = new FastWriter();
            //Your Code Here
            String s = in.next();
            calc(s);
            out.close();
        } catch (Exception e) {
            return;
        }

    }

    private static void calc(String s) {
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left.add(i + 1);
            }
            if (s.charAt(s.length() - 1 - i) == ')') {
                right.add(s.length() - i);
            }
        }
        //  Collections.reverse(right);
        int count = 0;
        for (int i = 0; i < Math.min(left.size(), right.size()); i++) {
            if (left.get(i) < right.get(i)) {
                count++;
            } else {
                break;
            }
        }
//        out.println(count);
//        out.println(right);
        if (count == 0) {
            out.println(0);
        } else {
            out.println(1);
            out.println(2 * count);
            for (int i = 0; i < count; i++) {
                out.print(left.get((i)) + " ");
            }
            for (int i = count-1; i >= 0; i--) {
                out.print(right.get(i) + " ");
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
