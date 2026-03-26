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
            int a = input.nextInt();
            int b = input.nextInt();
            int c = input.nextInt();
            int min = b-a+c-b, toA, toB, m;
            int[] triples = new int[]{b, b, b};
            int start = Math.max(a-min,0), end = c+min;
            for(int i = start+1; i <= end; ++i) {
                toA = countMove(a, i);
                if(toA >= min) continue;
                for(int j = i; j < end; j += i) {
                    toB = countMove(b, j);
                    if(toB+toA >= min) continue;
                    for(int k = j; k < end; k += j) {
                        m = toA+toB+countMove(c, k);
                        if(m < min) {
                            triples[0] = i;
                            triples[1] = j;
                            triples[2] = k;
                            min = m;
                        }
                    }
                }
            }
            output.append(min);
            output.append("\n");
            output.append(triples[0]);
            output.append(" ");
            output.append(triples[1]);
            output.append(" ");
            output.append(triples[2]);
            output.append(" ");
            output.append("\n");
            --t;
        }
        System.out.print(output);
    }
    static int countMove(int from, int to) {
        if(to > from) return to-from;
        return from-to;
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