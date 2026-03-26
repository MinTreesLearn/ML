import java.util.*;
import java.io.*;

public class B612 {
    static ArrayList<Integer> [] adj;
    static int [] c, a, sz;
    static boolean bad;
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        adj = new ArrayList[n + 1]; sz = new int[n + 1];
        c = new int[n + 1]; a = new int[n + 1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        int root = -1;
        for (int i = 1; i <= n; i++) {
            int p = sc.nextInt(); int less = sc.nextInt();
            c[i] = less;
            if (p == 0) {
                root = i; continue;
            }
            adj[p].add(i);
            adj[i].add(p);
        }
        ArrayList<Integer> vals = new ArrayList<>();
        for (int i = 1; i <= n; i++) vals.add(i);
        dfs1(root, -1);
        dfs(root, -1, vals);
        if (bad) {
            out.println("NO");
        } else {
            out.println("YES");
            for (int i = 1; i <= n; i++) out.print(a[i] + " ");
        }
        out.close();
    }

    static void dfs1(int cur, int par) {
        sz[cur] = 1;
        for (Integer next: adj[cur]) {
            if (next != par) {
                dfs1(next, cur);
                sz[cur] += sz[next];
            }
        }
    }

    static void dfs(int cur, int par, ArrayList<Integer> vals) {
        int seen = 0;
        if (c[cur] >= sz[cur]) {
            bad = true;
            return;
        }
        for (Integer i: vals) {
            if (seen == c[cur]) {
                a[cur] = i;
            }
            ++seen;
        }
        vals.remove((Object) a[cur]);
        int idx = 0; boolean ok = true;
        for (Integer next: adj[cur]) {
            if (next != par) {
                 ArrayList<Integer> add = new ArrayList<>();
                 if (idx + sz[next] - 1 > vals.size() - 1) {
                     ok = false; break;
                 }
                 int finish = idx + sz[next] - 1;
                 for (; idx <= finish; idx++) {
                     add.add(vals.get(idx));
                 }
                 idx = finish + 1;
                 dfs(next, cur, add);
            }
        }
        if (!ok) {
            bad = true;
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