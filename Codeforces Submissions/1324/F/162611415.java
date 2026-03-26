import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
public class Solution {
    static int n;
    static int[] a;
    static List<Integer>[] adjacents;
    static int[] parent;
    static int[] answer;
    public static void main(String[] args) throws IOException {
        Reader input = new Reader();
        n = input.nextInt();
        a = new int[n];
        for(int i = 0; i < n; ++i) a[i] = input.nextInt();
        adjacents = new List[n];
        for(int i = 0; i < n; ++i) adjacents[i] = new ArrayList<Integer>();
        int u, v;
        for(int i = 1; i < n; ++i) {
            u = input.nextInt()-1;
            v = input.nextInt()-1;
            adjacents[u].add(v);
            adjacents[v].add(u);
        }
        parent = new int[n];
        answer = new int[n];
        dfs(0, -1);
        dfs(0);
        solve();
        StringBuilder output = new StringBuilder();
        for(int i = 0; i < n; ++i) {
            output.append(answer[i]);
            output.append(" ");
        }
        System.out.print(output);
    }
    static void solve() {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(0);
        while(! queue.isEmpty()) {
            int node = queue.poll();
            for(int adjacent : adjacents[node]) {
                if(adjacent != parent[node]) {
                    int v = answer[node]-(answer[adjacent] > 0 ? answer[adjacent] : 0);
                    answer[adjacent] = answer[adjacent]+(v > 0 ? v : 0);
                    queue.add(adjacent);
                }
            }
        }
    }
    static void dfs(int node) {
        int best = a[node] == 0 ? -1 : 1;
        for(int adjacent : adjacents[node]) {
            if(adjacent != parent[node]) {
                dfs(adjacent);
                if(answer[adjacent] > 0) {
                    best += answer[adjacent];
                }
            }
        }
        answer[node] = best;
    }
    static void dfs(int node, int p) {
        parent[node] = p;
        for(int adjacent : adjacents[node]) {
            if(adjacent != parent[node]) {
                dfs(adjacent, node);
            }
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