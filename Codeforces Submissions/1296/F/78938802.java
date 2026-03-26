import java.util.*;
import java.io.*;
import javafx.util.Pair;
public class F617
{
    static int memo[][];
    static int [] depth; static int [] parent;
    static ArrayList<Integer> [] adj;
    static int log;
    public static void main(String [] args)
    {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        adj = new ArrayList [n + 1];
        log = (int)Math.ceil(Math.log(n) / Math.log(2));
        memo = new int[n + 1][log + 1];
        depth = new int[n + 1];
        parent = new int [n+1];
        for (int i = 0; i <= n; i++)
            Arrays.fill(memo[i], -1);
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        Pair<Integer, Integer> [] edges = new Pair [n-1];
        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt(); int b = sc.nextInt();
            adj[a].add(b); adj[b].add(a);
            edges[i] = new Pair(a, b);
        }
        dfs(1, 1);
        int m = sc.nextInt();
        Query [] queries = new Query[m];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt(); int b = sc.nextInt(); int g = sc.nextInt();
            queries[i] = new Query(a, b, g);
        }
        Arrays.sort(queries); int [] bound = new int [n+1]; boolean ans = true;
        for (int i = 0; i < m; i++) {
            int start1 = queries[i].a; int start2 = queries[i].b; int beaut = queries[i].beauty; int lca = lca(start1, start2);
            boolean changed = false;
            while (start1 != lca) {
                int temp = bound[start1];
                bound[start1] = Math.max(bound[start1], beaut);
                if (bound[start1] != temp || temp == beaut) changed = true;
                start1 = parent[start1];
            }
            while (start2 != lca) {
                int temp = bound[start2];
                bound[start2] = Math.max(bound[start2], beaut);
                if (bound[start2] != temp || temp == beaut) changed = true;
                start2 = parent[start2];
            }
            if (!changed) ans = false;
        }
        HashSet<Integer> set = new HashSet<>();
        for (int i = 2; i <= n; i++) set.add(bound[i]);
        for (int i = 0; i < m; i++) {
            if (!set.contains(queries[i].beauty)) {
                ans = false; break;
            }
        }
        if (ans) {
            for (int i = 0; i < n -1; i++) {
                Integer a = edges[i].getKey();
                Integer b = edges[i].getValue();
                if (parent[a] == b) {
                    out.print(bound[a] == 0 ? 1 + " " : bound[a] + " ");
                } else {
                    out.print(bound[b] == 0 ? 1 + " " : bound[b] + " ");
                }
            }
        } else {
            out.println(-1);
        }

        out.close();
    }

    static class Query implements Comparable<Query> {
        int a; int b; int beauty;
        Query(int a , int b, int beauty) {
            this.a = a; this.b = b; this.beauty = beauty;
        }
        public int compareTo(Query q) {
            return q.beauty - beauty;
        }
    }

    static void dfs(int u, int p)
    {

        // Using recursion formula to calculate
        // the values of memo[][]
        parent[u] = p;
        memo[u][0] = p;
        for (int i = 1; i <= log; i++)
            memo[u][i] = memo[memo[u][i - 1]][i - 1];
        for (int v : adj[u]) {
            if (v != p) {

                // Calculating the level of each node
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    }



    static int lca(int u, int v)
    {
        // The node which is present farthest
        // from the root node is taken as u
        // If v is farther from root node
        // then swap the two
        if (depth[u] < depth[v]) {
            int temp = u;
            u = v;
            v = temp;
        }

        // Finding the ancestor of u
        // which is at same level as v
        for (int i = log; i >= 0; i--) {
            if ((depth[u] - (int)Math.pow(2, i)) >= depth[v])
                u = memo[u][i];
        }

        // If v is the ancestor of u
        // then v is the LCA of u and v
        if (u == v)
            return u;

        // Finding the node closest to the root which is
        // not the common ancestor of u and v i.e. a node
        // x such that x is not the common ancestor of u
        // and v but memo[x][0] is
        for (int i = log; i >= 0; i--) {
            if (memo[u][i] != memo[v][i]) {
                u = memo[u][i];
                v = memo[v][i];
            }
        }

        // Returning the first ancestor
        // of above found node
        return memo[u][0];
    }


    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }



    }

}