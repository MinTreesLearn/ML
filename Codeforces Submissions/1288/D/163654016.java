import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;
public class Solution {
    static int n, m;
    static int[][] arrays;
    static int[][][] memo;
    static int[] depends;
    static int mp;
    public static void main(String[] args) throws IOException {
        Reader input = new Reader();
        n = input.nextInt();
        m = input.nextInt();
        arrays = new int[n][m];
        int max = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                arrays[i][j] = input.nextInt();
                if(arrays[i][j] > max) max = arrays[i][j];
            }
        }
        mp = (int)Math.pow(2, m);
        int left = 0, right = max+1, middle, i = 0, j = 0;
        while(left < right) {
            middle = left+right>>1;
            int[] a = solve(middle);
            if(a != null) {
                i = a[0];
                j = a[1];
                left = middle+1;
            } else {
                right = middle;
            }
        }
        System.out.print(i+1 + " " + (j+1));
    }
    static int[] solve(int x) {
        boolean[] set = new boolean[mp];
        List<Integer>[] d = new List[mp];
        for(int i = 0; i < mp; ++i) d[i] = new ArrayList<Integer>();
        for(int i = 0; i < n; ++i) {
            int t = 0;
            for(int j = 0; j < m; ++j) {
                int mask = (1 << j);
                if(arrays[i][j] >= x) {
                    t |= mask;
                }
            }
            set[t] = true;
            d[t].add(i);
        }
        for(int i = 0; i < mp; ++i) {
            if(!set[i]) continue;
            for(int j = 0; j < mp; ++j) {
                if(!set[j]) continue;
                if((i|j) == mp-1) {
                    return new int[]{d[i].get(0), d[j].get(0)};
                }
            }
        }
        return null;
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