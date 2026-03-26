import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
    static int n, o = 0, e = 0;
    static int[] a;
    static Integer[][][] memo;
    static int[] zeros;
    public static void main(String[] args) throws IOException {
        Reader input = new Reader();
        n = input.nextInt();
        a = new int[n];
        for(int i = 0; i < n; ++i) {
            a[i] = input.nextInt();
        }
        boolean[] used = new boolean[n+1];
        zeros = new int[n];
        for(int i = 0; i < n; ++i) {
            used[a[i]] = true;
            zeros[i] = (a[i] == 0 ? 1 : 0)+(i > 0 ? zeros[i-1] : 0);
        }
        for(int i = 1; i <= n; ++i) {
            if(!used[i]) {
                if(i%2 == 0) ++e;
                else ++o;
            }
        }
        memo = new Integer[n][e+1][2];
        System.out.println(solve(0, e, 0));
    }
    static int solve(int p, int evens, int prevParty) {
        if(p >= n) {
            return 0;
        }
        if(memo[p][evens][prevParty] != null) {
            return memo[p][evens][prevParty];
        }
        int answer = n+1;
        if(a[p] != 0) {
            answer = p == 0 ? 0 : (a[p]%2 == prevParty ? 0 : 1);
            answer += solve(p+1, evens, a[p]%2);
        } else {
            if(evens > 0) {
                int test = p == 0 ? 0 : (prevParty == 0 ? 0 : 1);
                test += solve(p+1, evens-1, 0);
                answer = Math.min(test, answer);
            }
            int odds = p == 0 ? o : (o-(zeros[p-1]-(e-evens)));
            if(odds > 0) {
                int test = p == 0 ? 0 : (prevParty == 0 ? 1 : 0);
                test += solve(p+1, evens, 1);
                answer = Math.min(test, answer);
            }
        }
        memo[p][evens][prevParty] = answer;
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