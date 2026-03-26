import java.io.*;
import java.util.*;

public class D
{
    static void solve(FastIO io)
    {
        int n = io.nextInt();
        int[] c = new int[n];
        int[] p = new int[n];

        int[] numC = new int[n];
        ArrayList<Integer>[] adj = new ArrayList[n];
        ArrayList<Integer>[] lists = new ArrayList[n];

        int root = -1;

        for (int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();

        for (int i = 0; i < n; i++)
        {
            p[i] = io.nextInt() - 1;
            c[i] = io.nextInt();
            
            if (p[i] == -1)
                root = i;
            else
            {
                numC[p[i]]++;
                adj[p[i]].add(i);
            }
        }


        ArrayDeque<Integer> stk = new ArrayDeque<>();

        for (int i = 0; i < n; i++)
        {
            if (numC[i] == 0)
                stk.push(i);
        }

        while (!stk.isEmpty())
        {
            int u = stk.pop();
            lists[u] = new ArrayList<>();

            if (c[u] == 0)
            {
                lists[u].add(u);
                c[u]--;
            }

            for (int v : adj[u])
            {
                for (int k : lists[v])
                {
                    lists[u].add(k);

                    c[u]--;

                    if (c[u] == 0)
                    {
                        lists[u].add(u);
                        c[u]--;
                    }
                }
            }

            if (p[u] != -1)
            {
                numC[p[u]]--;
                if (numC[p[u]] == 0)
                    stk.push(p[u]);
            }
        }

        if (lists[root] == null || lists[root].size() != n)
        {
            io.println("NO");
            return;
        }
        
        io.println("YES");
        int[] ans = new int[n];
        for (int i = 0; i < n; i++)
            ans[lists[root].get(i)] = i+1;
        
        for (int i = 0; i < n; i++)
            io.print(ans[i] + " ");

        io.println();
    }

    public static void main(String[] args) 
    {
        FastIO io = new FastIO();

        solve(io);

        io.close();
    }

    static class FastIO extends PrintWriter
    {
        StringTokenizer st = new StringTokenizer("");
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        FastIO()
        {
            super(System.out);
        }

        String next()
        {
            while (!st.hasMoreTokens())
            {
                try {
                    st = new StringTokenizer(r.readLine());
                } catch (Exception e) { }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }
    }
}