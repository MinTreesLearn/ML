import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main implements Runnable
{
    boolean multiple = true;
    long MOD;

    @SuppressWarnings("Duplicates")
    void solve() throws Exception
    {
        int n = sc.nextInt();
        int d = sc.nextInt();
        int N = n;
        int min = 0;

        for (int layer = 0; N > 0; layer++)
        {
            min += layer * min(N, 1 << layer);
            N -= 1 << layer;
        }

        if (min <= d && d <= (n * (n - 1)) / 2)
        {
            System.out.println("YES");
            PriorityQueue<Node>[] layer = new PriorityQueue[n + 1];
            layer[0] = new PriorityQueue<>();
            layer[1] = new PriorityQueue<>();
            layer[1].add(new Node(null, 1));
            for (int i = 2; i <= n; i++)
            {
                layer[i] = new PriorityQueue<>();
                layer[i].add(new Node(layer[i - 1].peek(), i));
            }

            int current = n;
            int lowest = n;

            for (int sum = (n * (n - 1)) / 2; sum > d; sum--)
            {
//                System.out.println(current);
                Node next = layer[current].poll();
                Node newParent = layer[current - 2].poll();
                next.parent.children--;
//                System.out.println(newParent.children);
                newParent.children++;
                next.parent = newParent;
                layer[current - 2].add(newParent);
                layer[current - 1].add(next);

                if (layer[lowest].isEmpty()) lowest--;

                current--;
                if (current == 2 || layer[current - 2].peek().children == 2) current = lowest;
            }

            int[] ans = new int[n + 1];
            for (PriorityQueue<Node> pq : layer)
                while (!pq.isEmpty())
                {
                    Node next = pq.poll();
                    if (next.idx == 1) continue;
                    ans[next.idx] = next.parent.idx;
                }

            for (int i = 2; i <= n; i++)
                System.out.print(ans[i] + " ");
            System.out.println();
        }
        else
            System.out.println("NO");
    }

    class Node implements Comparable<Node>
    {
        Node parent;
        int idx;
        int children = 1;

        Node(Node p, int i)
        {
            parent = p;
            idx = i;
        }

        @Override
        public int compareTo(Node o)
        {
            return children - o.children;
        }
    }

    long inv(long a, long b)
    {
        return 1 < a ? b - inv(b % a, a) * b / a : 1;
    }

    long gcd(long a, long b)
    {
        return a == 0 ? b : gcd(b % a, a);
    }

    long lcm(long a, long b) { return (a * b) / gcd(a , b); }

    class SegNode
    {
        int max;
        int L, R;
        SegNode left = null, right = null;

        int query(int queryL, int queryR)
        {
            if (queryL == L && queryR == R)
                return max;

            int leftAns = Integer.MIN_VALUE, rightAns = Integer.MIN_VALUE;
            if (left != null && queryL <= left.R)
                leftAns = left.query(queryL, min(queryR, left.R));
            if (right != null && queryR >= right.L)
                rightAns = right.query(max(queryL, right.L), queryR);

            return max(leftAns, rightAns);
        }

        SegNode(int[] arr, int l, int r)
        {
            L = l;
            R = r;
            max = arr[l];

            if (l == r) return;

            int mid = (l + r) / 2;
            left = new SegNode(arr, l, mid);
            right = new SegNode(arr, mid + 1, r);
            max = max(left.max, right.max);
        }
    }

    void print(long[] arr)
    {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    @Override
    public void run()
    {
        try
        {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            sc = new FastScanner(in);
            if (multiple)
            {
                int q = sc.nextInt();
                for (int i = 0; i < q; i++)
                    solve();
            }
            else
                solve();
        }
        catch (Throwable uncaught)
        {
            Main.uncaught = uncaught;
        }
        finally
        {
            out.close();
        }
    }

    public static void main(String[] args) throws Throwable
    {
        Thread thread = new Thread(null, new Main(), "", (1 << 26));
        thread.start();
        thread.join();
        if (Main.uncaught != null) {
            throw Main.uncaught;
        }
    }

    static Throwable uncaught; BufferedReader in; FastScanner sc; PrintWriter out;
}

class FastScanner
{
    BufferedReader in;
    StringTokenizer st;

    public FastScanner(BufferedReader in)
    {
        this.in = in;
    }

    public String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }
}