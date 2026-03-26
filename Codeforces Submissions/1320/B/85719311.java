import java.io.*;
import java.util.*;
public class Codeforces1320B
{
    public static long MOD = 1000000007;
    public static int n, m, k;
    public static ArrayList<Integer>[] adj;
    public static boolean[] vis;
    public static int[] p, x, y, count, dist;

    public static void bfs(int a)
    {
        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(a);
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[a] = 0;
        vis[a] = true;
        while (!queue.isEmpty())
        {
            int cur = queue.poll();
            for (int i : adj[cur])
            {
                dist[i] = Math.min(dist[i], dist[cur]+1);
                if (!vis[i])
                {
                    vis[i] = true;
                    queue.add(i);
                }
            }
        }
    }
    public static void main(String[] args)throws Exception
    {
        FastIO sc = new FastIO();
        n = sc.nextInt();
        m = sc.nextInt();
        adj = new ArrayList[n];
        dist = new int[n];
        vis = new boolean[n];
        x = new int[m];
        y = new int[m];
        count = new int[n];
        for (int i=0; i<n; i++)
            adj[i] = new ArrayList<>();
        for (int i=0; i<m; i++)
        {
            x[i] = sc.nextInt()-1;
            y[i] = sc.nextInt()-1;
            adj[y[i]].add(x[i]);
        }
        k = sc.nextInt();
        p = new int[k];
        for (int i=0; i<k; i++)
            p[i] = sc.nextInt()-1;
        bfs(p[k-1]);
        for (int i=0; i<m; i++)
            if (dist[y[i]]+1 == dist[x[i]])
                count[x[i]]++;
        int min = 0, max = 0;
        for (int i=0; i<k-1; i++)
        {
            if (dist[p[i+1]]+1 > dist[p[i]])
            {
                min++;
                max++;
            }
            else if (count[p[i]] > 1)
                max++;
        }
        System.out.println(min + " " + max);
    }
    static class FastIO {
        BufferedReader br;
        StringTokenizer st;

        public FastIO() {
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