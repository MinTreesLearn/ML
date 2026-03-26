import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
    static Reader input = new Reader();
    static int n;
    static int[] a;
    static int[][] segment;
    static Integer[][] memo;
    public static void main(String[] args) throws IOException {
        n = input.nextInt();
        a = new int[n];
        for(int i = 0; i < n; ++i) a[i] = input.nextInt();
        segment = new int[n][n];
        for(int i = 0; i < n; ++i) {
            segment[i][i] = a[i];
        }
        int e;
        for(int s = 2; s <= n; ++s) {
            for(int i = 0; i <= n-s; ++i) {
                e = i+s-1;
                for(int j = i; j < e; ++j) {
                    if(segment[i][j] == segment[j+1][e] && segment[i][j] != 0) {
                        segment[i][e] = segment[i][j]+1;
                        break;
                    }
                }
            }
        }
        memo = new Integer[n][n];
        System.out.print(solve(0, 0));
    }
    static int solve(int i, int start) {
        if(i == n-1) {
            if(segment[start][i] != 0) {
                return 1;
            }
            return n;
        }
        if(memo[i][start] != null) {
            return memo[i][start];
        }
        int min = n;
        if(segment[start][i] != 0) {
            min = Math.min(1+solve(i+1, i+1), solve(i+1, start));
        } else {
            min = solve(i+1, start);
        }
        memo[i][start] = min;
        return min;
    }
    static class Reader {
        BufferedReader bufferedReader;
        StringTokenizer string;
        public Reader() {
            InputStreamReader inr = new InputStreamReader(System.in);
            bufferedReader = new BufferedReader(inr);
        }
        public String next() throws IOException {
            while(string == null || ! string.hasMoreElements()) {
                string = new StringTokenizer(bufferedReader.readLine());
            }
            return string.nextToken();
        }
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        public String nextLine() throws IOException {
            return bufferedReader.readLine();
        }
    }
}