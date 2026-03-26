import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;
 
public class MaximumWhiteSubtree {
    boolean[] isWhite;
    int[] max;
    ArrayList<Integer> adj[];
    //ArrayList<HashSet<Integer>> containsThem;
 
    public static void main(String[] args) throws IOException {
        new MaximumWhiteSubtree().solve();
    }
 
    public void solve() throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(f.readLine());
        StringTokenizer tokenizer = new StringTokenizer(f.readLine());
        this.isWhite = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (Integer.parseInt(tokenizer.nextToken()) == 1) {
                isWhite[i] = true;
            }
        }
        this.adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            this.adj[i] = new ArrayList<>();
            //this.containsThem.add(new HashSet<Integer>());
        }
        for (int i = 0; i < n - 1; i++) {
            tokenizer = new StringTokenizer(f.readLine());
            int a = Integer.parseInt(tokenizer.nextToken()) - 1;
            int b = Integer.parseInt(tokenizer.nextToken()) - 1;
            adj[a].add(b);
            adj[b].add(a);
        }
        this.max = new int[n];
 
        dfs(0, -1);
        dfs2(0, -1);
        PrintWriter out = new PrintWriter(System.out);
        out.print(this.max[0]);
        for (int i = 1; i < n; i++) {
            out.print(" ");
            out.print(this.max[i]);
        }
 
        out.println();
        out.close();
    }
 
    private void dfs(int node, int parent) {
        if (this.isWhite[node]) {
            this.max[node]++;
        } else {
            this.max[node]--;
        }
 
        for (int adjacent : this.adj[node]) {
            if (adjacent == parent) {
                continue;
            }
            dfs(adjacent, node);
            if (this.max[adjacent] > 0) {
                this.max[node] += this.max[adjacent];
               // this.containsThem.get(node).add(adjacent);
            }
        }
    }
 
    private void dfs2(int node, int parent) {
        for (int adjacent : adj[node]) {
            if (adjacent == parent) {
                continue;
            }
            if (this.max[adjacent] > 0) {
                this.max[adjacent] = Math.max(this.max[adjacent], this.max[node]);
            } else {
                this.max[adjacent] = Math.max(this.max[adjacent], this.max[node] + this.max[adjacent]);
            }
            dfs2(adjacent, node);
        }
    }
}