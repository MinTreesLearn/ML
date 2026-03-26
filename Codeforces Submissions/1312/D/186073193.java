import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
    static final Reader input = new Reader();
    static final int MOD = 998244353;
    static int n, m;
    static long[] fac;
    public static void main(String[] args) throws IOException {
        n = input.nextInt();
        m = input.nextInt();
        if(n == 2) {
            System.out.println(0);
            return;
        }
        fac = new long[m+1];
        fac[0] = 1;
        fac[1] = 1;
        for(int i = 2; i < fac.length; ++i) fac[i] = (i*fac[i-1]) % MOD;
        long common = 0;
        for(int x = n-2; x < m; ++x) {
            common += (((fac[x-1] * inverse(fac[x-1 - (n-3)])) % MOD) * x ) % MOD;
            if(common >= MOD) common -= MOD;
        }
        long answer = 0;
        for(int i = 1; i < n-1; ++i) {
            answer += (common * inverse((fac[i-1]*fac[(n-1)-i-1]) % MOD)) % MOD;
            if(answer >= MOD) answer -= MOD;
        }
        System.out.println(answer);
    }
    static long inverse(long a) {
        return power(a, MOD-2);
    }
    static long power(long a, long b) {
        long result = 1;
        while(b > 0) {
            if(b % 2 == 1) result = (result*a)%MOD;
            a = (a*a) % MOD;
            b /= 2;
        }
        return result;
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
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}