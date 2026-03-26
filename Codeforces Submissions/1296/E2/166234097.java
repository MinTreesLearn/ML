import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Set;
import java.util.HashSet;
public class Solution {
    static Reader input = new Reader();
    static int n;
    static char[] s;
    static int[] colors;
    static int color = 1;
    public static void main(String[] args) throws IOException {
        n = input.nextInt();
        s = input.next().toCharArray();
        colors = new int[n];
        coloring();
        StringBuilder output = new StringBuilder();
        output.append(color-1);
        output.append("\n");
        for(int i = 0; i < n; ++i) {
            output.append(colors[i]);
            output.append(" ");
        }
        System.out.print(output);
    }
    static void coloring() {
        Set<Integer>[] used = new Set[26];
        for(int i = 0; i < 26; ++i) used[i] = new HashSet<Integer>();
        for(int i = 0; i < n; ++i) {
            boolean[] set = new boolean[color];
            for(int j = s[i]-'a'+1; j < 26; ++j) {
                for(int u : used[j]) {
                    set[u] = true;
                }
            }
            int x = -1;
            for(int j = 1; j < color; ++j) {
                if(!set[j]) {
                    x = j;
                    break;
                }
            }
            if(x == -1) {
                x = color;
                ++color;
            }
            colors[i] = x;
            used[s[i]-'a'].add(x);
        }
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