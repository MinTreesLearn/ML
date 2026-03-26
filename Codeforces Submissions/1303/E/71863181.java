/**
 * ******* Created  on 25/2/20 12:44 PM*******
 */

import java.io.*;
import java.util.*;
// t = a+b

public class ED82E implements Runnable {

    private static final int MAX = (int) (1E5 + 5);
    private static final int MOD = (int) (1E9 + 7);
    private static final long Inf = (long) (1E14 + 10);
    long[][] nxt = new long[405][26];
    private void solve() throws IOException {
        int t = reader.nextInt();
        while(t-- >0){
            String s = reader.next();
            String p = reader.next();
            int n = s.length();
            for(int i=0;i<405;i++)
                for(int j=0;j<26;j++)
                    nxt[i][j] = Inf;
            for(int i=n-1;i>=0;i--){
                for(int j=0;j<26;j++)
                    nxt[i][j] = nxt[i+1][j];
                nxt[i][s.charAt(i)-'a']=i;
            }

            int pn = p.length();
            boolean flag =false;
            for(int i=0;i<p.length();i++){
                if(calc(p.substring(0,i),p.substring(i,pn),n)){
                    writer.println("YES");
                    flag =true;
                    break;
                }
            }
            if(!flag)
                writer.println("NO");
        }
    }
    long[][] dp = new long[405][405];
    private boolean calc(String s1, String s2, int n) {
        int n1 = s1.length();
        int n2 = s2.length();
        for(int i=0;i<=n1;i++)
            for(int j=0;j<=n2;j++)
                dp[i][j]=Inf;
        dp[0][0]=0;
        for(int i=0;i<=n1;i++){
            for(int j=0;j <=n2;j++){
                if(dp[i][j] > n)
                    continue;
                int len = (int) dp[i][j];


                if(i < n1 && nxt[len][s1.charAt(i)-'a']< Inf)
                    dp[i+1][j] = Math.min(dp[i+1][j], nxt[len][s1.charAt(i)-'a']+1);

                if(j < n2 && nxt[len][s2.charAt(j)-'a']< Inf)
                    dp[i][j+1] = Math.min(dp[i][j+1], nxt[len][s2.charAt(j)-'a']+1);
                if(dp[i][j] > n)
                    continue;


            }
        }
        if(dp[n1][n2]< Inf)
            return true;
        return false;
    }

    public static void main(String[] args) throws IOException {
        try (Input reader = new StandardInput(); PrintWriter writer = new PrintWriter(System.out)) {
            new ED82E().run();
        }
    }

    StandardInput reader;
    PrintWriter writer;

    @Override
    public void run() {
        try {
            reader = new StandardInput();
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    interface Input extends Closeable {
        String next() throws IOException;

        default int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        default long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        default double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        default int[] readIntArray() throws IOException {
            return readIntArray(nextInt());
        }

        default int[] readIntArray(int size) throws IOException {
            int[] array = new int[size];
            for (int i = 0; i < array.length; i++) {
                array[i] = nextInt();
            }
            return array;
        }

        default long[] readLongArray(int size) throws IOException {
            long[] array = new long[size];
            for (int i = 0; i < array.length; i++) {
                array[i] = nextLong();
            }
            return array;
        }
    }

    private static class StandardInput implements Input {
        private final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        private StringTokenizer stringTokenizer;

        @Override
        public void close() throws IOException {
            reader.close();
        }

        @Override
        public String next() throws IOException {
            if (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                stringTokenizer = new StringTokenizer(reader.readLine());
            }
            return stringTokenizer.nextToken();
        }
    }
}
