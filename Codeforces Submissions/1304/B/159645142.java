

import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Objects;
import java.util.StringTokenizer;

public class Problem1304B {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) throws IOException {
        int n = scanner.nextInt();
        int length = scanner.nextInt();
        HashSet<String > set = new HashSet<>();
        char [] ans = new char[n*length];
        Arrays.fill(ans,'0' );
        int l = 0;
        int r = ans.length-1;
        int finalLength = 0;
        for (int i =0;i<n;i++){
            String str = scanner.next();
            String sbr = new StringBuilder(str).reverse().toString();
            if (set.contains(sbr)){
                set.remove(sbr);
                for (int j  =0;j<length;j++){
                    ans[l++] = str.charAt(j);
                    ans[r--] = sbr.charAt(length-j-1);
                }
                finalLength+=2*length;
            }else {
                set.add(str);
            }
        }
        for(String s : set) {
            String t = new StringBuilder(s).reverse().toString();
            if(s.equals(t)) {
                finalLength += length;
                for(int j = 0; j < length; j++) {
                    ans[l++] = s.charAt(j);
                }
                break;
            }
        }

        System.out.println(finalLength);
        for (int i =0;i<length*n;i++){
            if (ans[i]!='0')
            System.out.print(ans[i]);
        }
        System.out.println();




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
