

import java.io.*;
import java.util.StringTokenizer;

public class Problem1293A {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) throws IOException {
        int tc = scanner.nextInt();
     out:   while (tc-->0){
            int n = scanner.nextInt();
            int s = scanner.nextInt();
            int k = scanner.nextInt();
            int [] array = new int[k];
            for (int i =0;i<k;i++){
                array[i]= scanner.nextInt();
            }
            for (int i =0;i<=k;i++){
                if (s -i>=1 && !exists(array,s-i)){
                    System.out.println(i);
                    continue out;
                }
                if (s+i<=n && !exists(array,s+i)){
                    System.out.println(i);
                    continue out;
                }
            }


        }

    }
    static boolean exists(int [] array , int x ){
        boolean yes = false;
        for (int i =0;i<array.length;i++){
            if (array[i]==x){
                yes = true;
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
