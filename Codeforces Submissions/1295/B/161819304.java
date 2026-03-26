import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
    public static void main(String[] args) throws IOException {
        Reader input = new Reader();
        int t = input.nextInt();
        StringBuilder output = new StringBuilder();
        while(t > 0) {
            int n = input.nextInt();
            int x = input.nextInt();
            char[] s = input.next().toCharArray();
            output.append(solve(x, n, s));
            --t;
            output.append("\n");
        }
        System.out.print(output);
    }
    static int solve(int x, int n, char[] s) {
        int[] balance = new int[n];
        balance[0] = s[0] == '0' ? 1 : -1;
        for(int i = 1; i < n; ++i) {
            balance[i] = balance[i-1] + (s[i] == '0' ? 1 : -1);
        }
        if(balance[n-1] == 0) {
            boolean hasX = false;
            for(int i = 0; i < n; ++i) {
                if(balance[i] == x) {
                    hasX = true;
                    break;
                }
            }
            if(hasX) return -1;
            else return 0;
        }
        int increase = balance[n-1];
        int count = x == 0 ? 1 : 0;
        for(int i = 0; i < n; ++i) {
            if(increase < 0) {
                if(balance[i] > x) {
                    int y = balance[i]-x;
                    if(y%(-increase) == 0) {
                        ++count;
                    }
                }
            } else {
                if(balance[i] < x) {
                    int y = x-balance[i];
                    if(y%increase == 0) {
                        ++count;
                    }
                }
            }
            if(balance[i] == x) {
                ++count;
            }
        }
        return count;
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