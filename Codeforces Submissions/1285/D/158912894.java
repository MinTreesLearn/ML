import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
    public static void main(String[] args) throws IOException {
        Reader input = new Reader();
        int n = input.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; ++i) {
            a[i] = input.nextInt();
        }
        int maxBit = getMaxBit(a);
        int mask = (1 << (maxBit-1));
        System.out.println(solve(a, mask));
    }
    static int solve(int[] a, int mask) {
        int answer = 0;
        while(mask > 0) {
            int zeros = 0;
            int ones = 0;
            for(int i = 0; i < a.length; ++i) {
                if((a[i]|mask) == a[i]) {
                    ++ones;
                } else {
                    ++zeros;
                }
            }
            if(zeros != 0 && ones != 0) {
                answer |= mask;
                int[] g1 = new int[ones];
                int[] g2 = new int[zeros];
                int onesPointer = 0, zerosPointer = 0;
                for(int i = 0; i < a.length; ++i) {
                    if((a[i]|mask) == a[i]) {
                        g1[onesPointer++] = a[i];
                    } else {
                        g2[zerosPointer++] = a[i];
                    }
                }
                int temp1 = solve(g1, mask>>1), temp2 = solve(g2, mask>>1);
                if(temp1 < temp2) {
                    answer = answer|temp1;
                } else {
                    answer = answer|temp2;
                }
                break;
            }
            mask = mask >> 1;
        }
        return answer;
    }
    static int getMaxBit(int[] a) {
        int max = a[0];
        for(int i = 1; i < a.length; ++i) {
            if(a[i] > max) max = a[i];
        }
        int bits = 0;
        while(max > 0) {
            ++bits;
            max = max>>1;
        }
        return bits;
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