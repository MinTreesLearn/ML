

import java.io.*;
import java.util.StringTokenizer;

public class Problem1288B {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) throws IOException {
        int tc = scanner.nextInt();
        while (tc-->0){
            int a = scanner.nextInt();
            int b = scanner.nextInt();

            long cnt = 0;
            for (long i =9;i<=b;i=i*10+9){
                cnt+=a;
            }
            System.out.println(cnt);


        }
    }
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader s) throws FileNotFoundException {
            br = new BufferedReader(s);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}
