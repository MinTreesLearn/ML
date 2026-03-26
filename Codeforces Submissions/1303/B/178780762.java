import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.in;
import static java.lang.System.out;

public class National_Project {
    public static void main(String[] args) {
        try {
            FastReader in = new FastReader();
            FastWriter out = new FastWriter();
            int test = in.nextInt();
            while (test > 0) {
                //Your Code Here
                int length = in.nextInt();
                int good = in.nextInt();
                int bad = in.nextInt();
                calc(length, good, bad);
                test--;
            }
            out.close();
        } catch (Exception e) {
            return;
        }

    }

    private static void calc(int length, int good_duration, int bad_duration) {
        long required = (length + 1) / 2;
        long good = good_duration;
        long ans = 0;
        //long good_count=0;
        if (length < good_duration) {
            ans = length;
        } else {
            ans += (required/good_duration)*(good_duration+bad_duration);
            if(required%good_duration==0)
            {
                ans-=bad_duration;
            }
            else
            {
                ans+=(required%good_duration);
            }


        }
        out.println(Math.max(ans,length));
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
