import java.io.*;
import java.util.*;

public class Main {
    static List<Integer>[] g;
    static void bfs(int u, int[] dis) {
        dis[u] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(u);
        while(!q.isEmpty()) {
            int v = q.peek();
            q.remove();
            for(int w: g[v]) 
                if(dis[w] > dis[v] + 1) {
                    dis[w] = dis[v] + 1;
                    q.add(w);
                }
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        g = new List[n];
        for(int i = 0; i < n; ++i)
            g[i] = new ArrayList<Integer>();
        ArrayList<Integer> a = new ArrayList<>();
        for(int i = 0; i < k; ++i)
            a.add(in.nextInt() - 1);
        for(int i = 0; i < m; ++i) {
            int u = in.nextInt() - 1, v = in.nextInt() - 1;
            g[u].add(v);
            g[v].add(u);
        }
        int[] d1 = new int[n];
        int[] dn = new int[n];
        Arrays.fill(d1, 100000000);
        Arrays.fill(dn, 100000000);
        bfs(0, d1);
        bfs(n - 1, dn);
        int best = 0, mx = -100000000;
        Collections.sort(a, new Comparator<Integer>() {
            @Override public int compare(Integer b, Integer c) {
                return d1[b] - dn[b] - d1[c] + dn[c];
            }     
        });
        for(int e: (List<Integer>) a) {
            best = Math.max(best, mx + dn[e]);
            mx = Math.max(mx, d1[e]);
        }
        System.out.println(Math.min(best + 1, d1[n - 1]));
    }
}