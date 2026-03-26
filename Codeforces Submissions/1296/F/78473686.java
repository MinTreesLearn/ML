import javax.swing.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BerlandBeauty {
    ArrayList<int[]>[] adj;
    int[] in;
    int[] out;
    int[][] parentOf;
    int time;
    int[] minBeauty;


    public static void main(String[] args) throws IOException {
        new BerlandBeauty().solve();
    }

    public void solve() throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(f.readLine());
        this.adj = new ArrayList[n];
        this.in = new int[n];
        this.out = new int[n];
        this.parentOf = new int[n][2];
        for (int i = 0; i < n; i++) {
            parentOf[i] = new int[2];
        }
        for (int i = 0; i < n; i++) {
            this.adj[i] = new ArrayList<int[]>();
        }
        for (int i = 0; i < n - 1; i++) {
            StringTokenizer tokenizer = new StringTokenizer(f.readLine());
            int a = Integer.parseInt(tokenizer.nextToken()) - 1;
            int b = Integer.parseInt(tokenizer.nextToken()) - 1;
            int[] ar1 = {a, i + 1};
            int[] ar2 = {b, i + 1};
            adj[a].add(ar2);
            adj[b].add(ar1);
        }

        this.time = 0;
        dfs1(0);
        adj = null;

        int m = Integer.parseInt(f.readLine());
        int[][] queries = new int[m][3];
        minBeauty = new int[n];
        Arrays.fill(minBeauty, 1);
        for (int i = 0; i < m; i++) {
            StringTokenizer tokenizer = new StringTokenizer(f.readLine());
            int a = Integer.parseInt(tokenizer.nextToken()) - 1;
            int b = Integer.parseInt(tokenizer.nextToken()) - 1;
            int min = Integer.parseInt(tokenizer.nextToken());
            queries[i][0] = a;
            queries[i][1] = b;
            queries[i][2] = min;
            this.dfs2(a, b, min);
            this.dfs2(b, a, min);
        }

        boolean isPossible = true;
        for (int i = 0; i < m; i++) {
            boolean currentIsGood = checkIfGood(queries[i][0], queries[i][1], queries[i][2]) || checkIfGood(queries[i][1], queries[i][0], queries[i][2]);
            isPossible = isPossible && currentIsGood;
        }

        PrintWriter out = new PrintWriter(System.out);
        if (isPossible) {
            out.print(minBeauty[1]);
            for (int i = 2; i <= n - 1; i ++) {
                out.print(" ");
                out.print(minBeauty[i]);
            }
            out.println();
        } else {
            out.println(-1);
        }

        out.close();
    }

    private void dfs1(int node) {
        this.in[node] = time++;
        for (int[] adjacent : adj[node]) {
            if (adjacent[0] != parentOf[node][0]) {
                parentOf[adjacent[0]][0] = node;
                parentOf[adjacent[0]][1] = adjacent[1];
                dfs1(adjacent[0]);
            }
        }
        this.out[node] = time++;
    }

    private boolean checkIfGood(int startNode, int otherNode, int minimum) {
        while (!(this.in[startNode] <= this.in[otherNode] && out[startNode] >= out[otherNode])) {
            int newNode = parentOf[startNode][0];
            //System.out.println(this.minBeauty[parentOf[startNode][1]] + " " + minimum);
            if (this.minBeauty[parentOf[startNode][1]] == minimum) {
                return true;
            }
            // System.out.println(parentOf[startNode][1] + " " + this.minBeauty[parentOf[startNode][1]]);
            startNode = newNode;
        }
        return false;
    }

    private void dfs2(int startNode, int otherNode, int minimum) {
       // System.out.println("wop " + startNode);
        while (!(this.in[startNode] <= this.in[otherNode] && out[startNode] >= out[otherNode])) {
            int newNode = parentOf[startNode][0];
            this.minBeauty[parentOf[startNode][1]] = Math.max(minBeauty[parentOf[startNode][1]], minimum);
           // System.out.println(parentOf[startNode][1] + " " + this.minBeauty[parentOf[startNode][1]]);
            startNode = newNode;
        }
    }
}
