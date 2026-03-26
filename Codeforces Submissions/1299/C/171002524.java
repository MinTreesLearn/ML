import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
public class Solution {
    static Reader input = new Reader();
    static int n;
    static int[] a;
    public static void main(String[] args) throws IOException {
        n = input.nextInt();
        a = new int[n];
        for(int i = 0; i < n; ++i) {
            a[i] = input.nextInt();
        }
        long[] dp = new long[n];
        int[] next = new int[n];
        double[] answer = new double[n];
        answer[n-1] = a[n-1];
        next[n-1] = n-1;
        dp[n-1] = a[n-1];
        for(int i = n-2; i > -1; --i) {
            dp[i] = a[i];
            next[i] = i;
            for(int j = i+1; j < n; j = next[j]+1) {
                if(((double)dp[i]/(double)(next[i]-i+1)) >= answer[j]) {
                    next[i] = next[j];
                    dp[i] += dp[j];
                } else break;
            }
            answer[i] = (double)dp[i]/(double)(next[i]-i+1);
        }
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int i = 0, j;
        String temp;
        while(i < n) {
            temp = String.format("%.9f", answer[i]);
            for(j = i; j <= next[i]; ++j) {
                writer.write(temp+"\n");
            }
            i = j;
        }
        writer.flush();
    }
    static class Reader {
        BufferedReader reader;
        StringTokenizer string;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }
        public String next() throws IOException {
            while(string == null || ! string.hasMoreElements()) {
                string = new StringTokenizer(reader.readLine());
            }
            return string.nextToken();
        }
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}