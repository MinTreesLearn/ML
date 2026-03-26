

import java.io.*;
import java.util.StringTokenizer;

public class Problem1288B {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) throws IOException {
        int tc = scanner.nextInt();
        while (tc-->0){
            int a = scanner.nextInt();
            int b = scanner.nextInt();

            int cnt = 0;

            if (a<9 && b<9) {
                System.out.println(0);
                continue;
            }
            boolean flag = allNine(b);
            while (b>0){
                cnt++;
                b/=10;
            }
            if (flag){
                long val = (long) cnt*a;
                System.out.println(val);
                continue;
            }
            long val = (long) a*(cnt-1);
            System.out.println(val);


        }
    }
    static boolean allNine(int b){
        boolean yes = true;
        String str = Integer.toString(b);
        for (int i =0;i<str.length();i++){
            if (str.charAt(i)!='9'){
                yes = false;
                break;
            }
        }
        return yes;
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
