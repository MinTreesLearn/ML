import java.io.*;
import java.util.*;
 
public class E
{
    static class SegNode
    {
        int lo, hi, mid;
        int sum, id = -1;
        SegNode left, right;

        SegNode(int a, int b)
        {
            lo = a;
            hi = b;
            mid = (lo + hi) / 2;

            if (lo != hi)
            {
                left = new SegNode(lo, mid);
                right = new SegNode(mid+1, hi);
            }
        }

        void set(int pos, int val, int id)
        {
            if (lo == hi)
            {
                sum = val;
                this.id = id;
                return;
            }

            if (pos <= mid)
                left.set(pos, val, id);
            else
                right.set(pos, val, id);

            sum = left.sum + right.sum;
        }

        int sum(int a, int b)
        {
            if (a <= lo && hi <= b)
                return sum;

            int val = 0;

            if (a <= mid)
                val += left.sum(a, Math.min(mid, b));
            if (mid+1 <= b)
                val += right.sum(Math.max(mid+1, a), b);

            return val;
        }

        int getId(int pos)
        {
            if (lo == hi)
                return id;

            if (pos <= mid)
                return left.getId(pos);
            else
                return right.getId(pos);
        }

    }
    static void solve(FastIO io)
    {
        int n = io.nextInt();
        int m = io.nextInt();

        int[] msg = new int[m];
        int[] min = new int[n];
        int[] max = new int[n];

        for (int i = 0; i < n; i++)
            min[i] = max[i] = i;

        for (int i = 0; i < m; i++)
        {
            msg[i] = io.nextInt() - 1;

            min[msg[i]] = 0;
        }

        int[] pos = new int[n];
        SegNode root = new SegNode(0, n + m);

        for (int i = 0; i < n; i++)
        {
            pos[i] = m + i;
            root.set(m+i, 1, i);
        }

        int ptr = m - 1;

        for (int i = 0; i < m; i++)
        {
            int k = msg[i];
            int p = root.sum(0, pos[k] - 1);

            max[k] = Math.max(max[k], p);

            root.set(pos[k], 0, -1);

            pos[k] = ptr--;

            root.set(pos[k], 1, k);
        }

        ptr = 0;

        for (int i = 0; i < n + m; i++)
        {
            int k = root.getId(i);
            if (k != -1)
                max[k] = Math.max(max[k], ptr++);
        }

        for (int i = 0; i < n; i++)
            io.println((min[i] + 1) + " " + (max[i] + 1));
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
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
    }
}