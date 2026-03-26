import java.io.*;
import java.util.*;

public class D
{
    class State implements Comparable<State>
    {
        int u, k;
        long d;
        State(int uu, int kk, long dd)
        {
            u = uu;
            k = kk;
            d = dd;
        }

        public int compareTo(State o)
        {
            return Long.compare(d, o.d);
        }
    }

    void solve(FastIO io)
    {
        int n = io.nextInt();
        int k = io.nextInt();
        long[][] adj = new long[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = io.nextInt();

        Random r = new Random();
        boolean[] col = new boolean[n];
        long[][] dist = new long[n][k+1];
        long oo = (long)1e12;

        long ans = oo;

        for (int z = 0; z < 5000; z++)
        {
            for (int i = 0; i < n; i++)
                col[i] = (r.nextInt() & 1) == 0;

            for (long[] i : dist)
                Arrays.fill(i, oo);

            PriorityQueue<State> q = new PriorityQueue<>();
            q.add(new State(0, 0, 0));
            dist[0][0] = 0;

            while (!q.isEmpty())
            {
                State s = q.remove();

                if (s.d > dist[s.u][s.k])
                    continue;

                if (s.k == k)
                {
                    if (s.u == 0)
                    {
                        ans = Math.min(ans, s.d);
                        break;
                    }
                    continue;
                }
                
                for (int v = 0; v < n; v++)
                {
                    if (s.u == v || col[s.u] == col[v])
                        continue;

                    if (dist[v][s.k+1] <= dist[s.u][s.k] + adj[s.u][v])
                        continue;

                    dist[v][s.k+1] = dist[s.u][s.k] + adj[s.u][v];
                    q.add(new State(v, s.k+1, dist[v][s.k+1]));
                }
            }
        }

        io.println(ans);
    }

    public static void main(String[] args)
    {
        FastIO io = new FastIO();

        new D().solve(io);

        io.close();
    }

    static class FastIO extends PrintWriter
    {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        FastIO()
        {
            super(System.out);
        }

        public String next()
        {
            while (!st.hasMoreTokens())
            {
                try {
                    st = new StringTokenizer(r.readLine());
                } catch (Exception e) {
                    //TODO: handle exception
                }
            }
            return st.nextToken();
        }

        public int nextInt()
        {
            return Integer.parseInt(next());
        }

        public long nextLong()
        {
            return Long.parseLong(next());
        }

        public double nextDouble()
        {
            return Double.parseDouble(next());
        }
    }
}

