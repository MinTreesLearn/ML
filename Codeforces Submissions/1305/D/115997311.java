import javax.print.attribute.HashAttributeSet;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
    static Map<Integer, Set<Integer>> map = new HashMap<>();
    static HashSet<Integer> leafList = new HashSet<>();
    static int n;
    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();
        int test = 1;
        for (int t = 0; t < test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            map.put(i, new HashSet<>());
        }
        for (int i = 0; i < n - 1; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            map.get(x).add(y);
            map.get(y).add(x);
        }
        leafList = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (map.get(i).size() == 1) {
                leafList.add(i);
            }
        }
        while (leafList.size() > 1) {
            int u = leafList.iterator().next();
            leafList.remove(u);
            int v = leafList.iterator().next();
            leafList.remove(v);
            int w = ask(u, v);
            if (w == u || w == v) {
                answer(w);
                return;
            }
            removeLeaf(u, -1, w);
            removeLeaf(v, -1, w);
            if (map.get(w).size() <= 1) {
                leafList.add(w);
            }
        }
        answer(leafList.iterator().next());
    }

    private static void removeLeaf(int leaf, int prev, int lca) {
        if (leafList.contains(leaf)) {
            leafList.remove(leaf);
        }
        for (int adj : map.get(leaf)) {
            if (adj == prev) {
                continue;
            }
            if (adj == lca) {
                map.get(adj).remove(leaf);
            }else if (map.get(adj).size() > 0) {
                removeLeaf(adj, leaf, lca);
            }
        }
        map.get(leaf).clear();
    }

    private static void answer(int root) {
        out.println("! " + (root + 1));
        out.flush();
    }

    private static int ask(int u, int v) {
        out.println("? " + (u + 1) + " " + (v + 1));
        out.flush();
        int w = sc.nextInt() - 1;
        return w;
    }

    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}