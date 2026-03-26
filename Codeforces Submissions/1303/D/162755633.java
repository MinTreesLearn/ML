import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
    static long n;
    static int m;
    static int[] a, map, v, needs;
    public static void main(String[] args) throws IOException {
        Reader input = new Reader();
        StringBuilder output = new StringBuilder();
        int t = input.nextInt();
        while(t > 0) {
            n = input.nextLong();
            m = input.nextInt();
            a = new int[m];
            for(int i = 0; i < m; ++i) a[i] = input.nextInt();
            long sum = 0;
            for(int i = 0; i < m; ++i) sum += (long)a[i];
            if(sum < n) {
                output.append(-1);
            } else {
                output.append(solve());
            }
            --t;
            output.append("\n");
        }
        System.out.print(output);
    }
    static long solve() {
        map = new int[30];
        v = new int[30];
        v[0] = 1;
        for(int i = 1; i < 30; ++i) {
            v[i] = v[i-1]*2;
        }
        for(int i = 0; i < m; ++i) {
            int left = 0, right = 30, middle;
            while(left < right) {
                middle = left+right>>1;
                if(v[middle] == a[i]) {
                    ++map[middle];
                    break;
                } else if(v[middle] > a[i]) {
                    right = middle;
                } else {
                    left = middle+1;
                }
            }
        }
        needs = new int[30];
        for(int i = 29; i > -1; --i) {
            needs[i] = (int)(n/v[i]);
            n -= (n/v[i])*(long)v[i];
        }
        for(int i = 29; i > -1; --i) {
            if(map[i] >= needs[i]) {
                map[i] -= needs[i];
                needs[i] = 0;
            } else {
                needs[i] -= map[i];
                map[i] = 0;
            }
        }
        long count = 0;
        for(int i = 0; i < 30; ++i) {
            if(map[i] >= needs[i]) {
                map[i] -= needs[i];
                needs[i] = 0;
                if(i+1 < 30) {
                    int temp = map[i]/2;
                    map[i+1] += temp;
                    map[i] -= temp*2;
                }
            } else {
                needs[i] -= map[i];
                map[i] = 0;
                for(int j = i+1; j < 30; ++j) {
                    if(map[j] > needs[j]) {
                        for(int k = j-1; k >= i; --k) {
                            ++map[k];
                            ++count;
                        }
                        ++map[i];
                        --map[j];
                        break;
                    }
                }
                --i;
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