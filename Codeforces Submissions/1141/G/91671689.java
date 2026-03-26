import java.util.*;
import java.io.*;

public class G547 {
    static ArrayList<Integer> [] adj;
    static boolean [] bad;
    static HashSet<Edge> colored;
    static Map<Edge, Integer> map;
    static int [] ret;
    static boolean [] vis;
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt(); int k = sc.nextInt();
        map = new HashMap<>();
        ret = new int[n - 1];
        adj = new ArrayList[n + 1];
        colored = new HashSet<>();
        vis = new boolean[n + 1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt(); int v = sc.nextInt();
            Edge e = new Edge(u, v);
            e.c = -1;
            colored.add(e);
            map.put(e, i);
            adj[u].add(v); adj[v].add(u);
        }
        ArrayList<Integer> deg = new ArrayList<>();
        for (int i = 1; i <= n; i++) deg.add(i);
        Collections.sort(deg, Comparator.comparingInt(x -> -adj[x].size()));
        bad = new boolean[n + 1];
        for (int i = 0; i < k; i++) bad[deg.get(i)] = true;
        //colored = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && !bad[i]) dfs(i, -1, -1);
        }
        for (int i = 1; i <= n; i++) {
            for (Integer a: adj[i]) {
                if (bad[i] && bad[a]) {
                    Edge toAdd = new Edge(i, a);
                    toAdd.c = 1;
                    Edge in = new Edge(i, a); in.c = -1;
                    colored.remove(in);
                    colored.add(toAdd);
                    ret[map.get(in)] = 1;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < n - 1; i++) max = Math.max(max, ret[i]);
        out.println(max);
        for (int i = 0; i < n - 1; i++) out.print(ret[i] + " ");
        out.close();
    }

    static void dfs(int cur, int par, int c) {
        vis[cur] = true;
        Edge toAdd = new Edge(cur, par); toAdd.c = c;
        if (par != -1) {
            Edge in = new Edge(cur, par); in.c = -1;
            colored.remove(in);
            colored.add(toAdd);
            ret[map.get(in)] = c;
        }
        if (bad[cur]) return;
        int start = 1;
        if (c == 1) ++start;
        for (Integer next: adj[cur]) {
            if (next != par) {
                dfs(next, cur, start);
                ++start;
                if (start == c) ++start;
            }
        }
    }

    static class Edge {
        int a; int b; int c;
        Edge(int u, int v) {
            this.a = Math.min(u, v); this.b = Math.max(u, v);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Edge edge = (Edge) o;
            return a == edge.a &&
                    b == edge.b &&
                    c == edge.c;
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b, c);
        }
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

        String nextLine() {
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