import java.io.*;
import java.util.*;

public class F
{
    //@ <- not printed in hackpack
    static class MinCostFlow {
        static int MINCOSTFLOW = 0, MINCOSTMAXFLOW = 1;
        int s, t, N, ss, tt;  // use s and t as your source & sink
        long oo = (long)1e12;
        long[] ex;  ArrayList<Edge>[] adjj;  Edge[][] adj;
        
        public MinCostFlow(int NN) {  this(NN, MINCOSTMAXFLOW);  }
        
        public MinCostFlow(int NN, int flowType) {
            N = (tt = (ss = (t = (s = NN) + 1) + 1) + 1) + 1;
            
            adj = new Edge[N][0];  adjj = new ArrayList[N];
            for (int i = 0; i < N; i++)  adjj[i] = new ArrayList<Edge>();
            ex = new long[N];  add(t, s, oo, -oo / 10 * flowType);
        }
        
        public void add(int i, int j, long cap, long cost) {
            Edge fwd = new Edge(i, j, cap, 0, cost);
            Edge rev = new Edge(j, i, 0, 0, -cost);
            adjj[i].add(rev.rev = fwd);  adjj[j].add(fwd.rev = rev);
        }

        public void add(int i, int j, long cap, long cost, int id, int ttype) {
            Edge fwd = new Edge(i, j, cap, 0, cost, id, ttype);
            Edge rev = new Edge(j, i, 0, 0, -cost, id, ttype);
            adjj[i].add(rev.rev = fwd);  adjj[j].add(fwd.rev = rev);
        }
        
        public long[] getFlow() {
            preFlow();
            for (int i = 0; i < N; i++)  adj[i] = adjj[i].toArray(adj[i]);
            boolean[] canU = new boolean[N], hasU = new boolean[N];
            long[] dist = new long[N], width = new long[N];
            Edge[] prev = new Edge[N];
            while (true) {
                Arrays.fill(dist, oo);  dist[ss] = 0;
                width[ss] = oo;  boolean updated = hasU[ss] = true;
                while (updated) {
                    updated = false;
                    for (int i = 0; i < N; hasU[i++] = false)  canU[i] = hasU[i];
                    for (int i = 0; i < N; i++)
                        if (canU[i])
                            for (Edge e : adj[i])
                                if (e.flow != e.cap && dist[e.j] > dist[e.i] + e.cost) {
                                    dist[e.j] = dist[e.i] + (prev[e.j] = e).cost;
                                    width[e.j] = Math.min(width[e.i], e.cap - e.flow);
                                    hasU[e.j] = updated = true;
                                }
                }
                if (dist[tt] >= oo)  break;
                
                for (Edge e = prev[tt]; e != null; e = prev[e.i])
                    e.rev.flow = -(e.flow += width[tt]);
            }
            long flow = 0, cost = 0;
            for (Edge e : adj[s])  if (e.flow > 0)  flow += e.flow;
            for (int i = 0; i < N; i++)
                for (Edge e : adj[i])
                    if (e.flow > 0 && e.i != t && e.j != s && e.i < ss && e.j < ss)
                        cost += e.flow * e.cost;
            
            return new long[] {flow, cost};
        }
        
        public void preFlow() {
            for (int i = 0; i < N; i++)
                for (Edge e : adjj[i])
                    if (e.cost < 0 && e.cap - e.flow > 0) {
                        ex[e.i] -= e.cap - e.flow;
                        ex[e.j] += e.cap - e.flow;
                        e.rev.flow = -(e.flow = e.cap);
                    }
            for (int i = 0; i < N; i++)
                if (ex[i] > 0)  add(ss, i, ex[i], -oo);
                else if (ex[i] < 0)  add(i, tt, -ex[i], -oo);
            Arrays.fill(ex, 0);
        }
        
    }		
    static class Edge {
        int i, j;  long cap, flow, cost;  Edge rev;
        int id = -1, type = 0;
        Edge(int ii, int jj, long cc, long ff, long C) {
            i = ii; j = jj; cap = cc; flow = ff; cost = C;
        }

        Edge(int ii, int jj, long cc, long ff, long C, int iid, int ttype) {
            i = ii; j = jj; cap = cc; flow = ff; cost = C;
            id = iid;
            type = ttype;
        }
    }

    void solve(FastIO io)
    {
        int n1 = io.nextInt();
        int n2 = io.nextInt();
        int m = io.nextInt();
        int r = io.nextInt();
        int b = io.nextInt();
        char[] s1 = io.next().toCharArray();
        char[] s2 = io.next().toCharArray();

        MinCostFlow mcmf = new MinCostFlow(n1 + n2, 0);
        long soo = 1000000;
        int cnt = n1 + n2;

        for (int i = 0; i < n1; i++)
        {
            if (s1[i] == 'R')
            {
                mcmf.add(mcmf.s, i, 1, -soo);
                mcmf.add(mcmf.s, i, 1000, 0);
            }
            else if (s1[i] == 'B')
            {
                mcmf.add(i, mcmf.t, 1, -soo);
                mcmf.add(i, mcmf.t, 1000, 0);
            }
            else
            {
                cnt--;
                mcmf.add(mcmf.s, i, 1000, 0);
                mcmf.add(i, mcmf.t, 1000, 0);
            }
        }

        for (int i = 0; i < n2; i++)
        {
            if (s2[i] == 'B')
            {
                mcmf.add(mcmf.s, i + n1, 1, -soo);
                mcmf.add(mcmf.s, i + n1, 1000, 0);
            }
            else if (s2[i] == 'R')
            {
                mcmf.add(i + n1, mcmf.t, 1, -soo);
                mcmf.add(i + n1, mcmf.t, 1000, 0);
            }
            else
            {
                cnt--;
                mcmf.add(mcmf.s, i + n1, 1000, 0);
                mcmf.add(i + n1, mcmf.t, 1000, 0);
            }
        }

        int[] from = new int[m];
        int[] to = new int[m];
        for (int i = 0; i < m; i++)
        {
            int u = from[i] = io.nextInt() - 1;
            int v = to[i] = io.nextInt() - 1;

            mcmf.add(u, n1 + v, 1, r, i, 1);
            mcmf.add(n1 + v, u, 1, b, i, -1);
        }

        long[] flow = mcmf.getFlow();

        if (flow[1] + cnt * soo > soo)
        {
            io.println(-1);
            return;
        }

        long ans = flow[1] + soo * cnt;

        long[] col = new long[m];
        long[] bal1 = new long[n1];
        long[] bal2 = new long[n2];
        for (ArrayList<Edge> list : mcmf.adjj)
            for (Edge e : list)
                if (e.id != -1 && e.flow > 0)
                {
                    col[e.id] = e.type;
                    bal1[from[e.id]] += e.type;
                    bal2[to[e.id]] += e.type;
                }

        
        for (int i = 0; i < n1; i++)
            if ((s1[i] == 'R' && bal1[i] <= 0) || (s1[i] == 'B' && bal1[i] >= 0))
            {
                io.println(-1);
                return;
            }

        for (int i = 0; i < n2; i++)
            if ((s2[i] == 'R' && bal2[i] <= 0) || (s2[i] == 'B' && bal2[i] >= 0))
            {
                io.println(-1);
                return;
            }
        io.println(ans);

        for (int i = 0; i < m; i++)
            io.print(col[i] > 0 ? 'R' : (col[i] < 0 ? 'B' : 'U'));

        io.println();
    }

    public static void main(String[] args)
    {
        FastIO io = new FastIO();
        
        new F().solve(io);

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

