import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
    static int n;
    static int[] a;
    static Integer[][][][] memo;
    public static void main(String[] args) throws IOException {
        Reader input = new Reader();
        n = input.nextInt();
        a = new int[n];
        for(int i = 0; i < n; ++i) {
            a[i] = input.nextInt();
        }
        boolean[] used = new boolean[n+1];
        for(int i = 0; i < n; ++i) {
            used[a[i]] = true;
        }
        int evens = 0, odds = 0;
        for(int i = 1; i <= n; ++i) {
            if(!used[i]) {
                if(i%2 == 0) ++evens;
                else ++odds;
            }
        }
        memo = new Integer[n][evens+1][odds+1][2];
        System.out.println(solve(0, evens, odds, 0));
    }
    static int solve(int p, int evens, int odds, int prevParty) {
        if(p >= n) {
            return 0;
        }
        if(memo[p][evens][odds][prevParty] != null) {
            return memo[p][evens][odds][prevParty];
        }
        int answer = n+1;
        if(a[p] != 0) {
            answer = p == 0 ? 0 : (a[p]%2 == prevParty ? 0 : 1);
            answer += solve(p+1, evens, odds, a[p]%2);
        } else {
            if(evens > 0) {
                int test = p == 0 ? 0 : (prevParty == 0 ? 0 : 1);
                test += solve(p+1, evens-1, odds, 0);
                answer = Math.min(test, answer);
            }
            if(odds > 0) {
                int test = p == 0 ? 0 : (prevParty == 0 ? 1 : 0);
                test += solve(p+1, evens, odds-1, 1);
                answer = Math.min(test, answer);
            }
        }
        memo[p][evens][odds][prevParty] = answer;
        return answer;
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