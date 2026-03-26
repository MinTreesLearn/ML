import java.io.*;
import java.util.*;

public class Main {
    static class Lca {
        int lim, t = 0, n;
        int[] tin, tout, d;
        int[][] up;
        public Lca(List<Integer>[] g, int u) {
            this.n = g.length;
            this.tin = new int[n];
            this.tout = new int[n];
            this.d = new int[n];
            this.lim = 31 - Integer.numberOfLeadingZeros(this.n);
            if(Integer.bitCount(this.n) != 1)
                ++this.lim;
            this.up = new int[this.n][this.lim + 1];
            dfs(g, u, u, 0);
        }
        void dfs(List<Integer>[] g, int u, int p, int dep) {
            tin[u] = ++t;
            up[u][0] = p;
            d[u] = dep;
            for(int i = 1; i <= lim; ++i) 
                up[u][i] = up[up[u][i - 1]][i - 1];
            for(int v: g[u])
                if(v != p)
                    dfs(g, v, u, dep + 1);
            tout[u] = ++t;
        }
        boolean is_anc(int u, int v) {
            return tin[u] <= tin[v] && tout[u] >= tout[v];
        }
        int lca(int u, int v) {
            if(is_anc(u, v))
                return u;
            if(is_anc(v, u))
                return v;
            for(int i = lim; i >= 0; --i)
                if(!is_anc(up[u][i], v))
                    u = up[u][i];
            return up[u][0];
        }
        int dis(int u, int v) {
            return d[u] + d[v] - 2 * d[lca(u, v)];
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        List<Integer>[] g = new List[n];
        for(int i = 0; i < n; ++i)
            g[i] = new ArrayList<Integer>();
        for(int i = 1; i < n; ++i) {
            int u = in.nextInt() - 1, v = in.nextInt() - 1;
            g[u].add(v);
            g[v].add(u);
        }
        Lca lca = new Lca(g, 0);
        int q = in.nextInt();
        while(q-- > 0) {
            int x = in.nextInt() - 1, y = in.nextInt() - 1;
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            int k = in.nextInt(), p = lca.dis(a, b);
            if(p <= k && p % 2 == k % 2) {
                System.out.println("YES");
                continue;
            }
            p = lca.dis(a, x) + lca.dis(b, y) + 1;
            if(p <= k && p % 2 == k % 2) {
                System.out.println("YES");
                continue;
            }
            p = lca.dis(a, y) + lca.dis(b, x) + 1;
            System.out.println(p <= k && p % 2 == k % 2 ? "YES" : "NO");
        }
    }
}