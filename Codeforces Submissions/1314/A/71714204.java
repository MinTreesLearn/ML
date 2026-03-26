import java.io.*;
import java.util.*;

public class A
{
 
    class Pair implements Comparable<Pair>
    {

        long x, t;
        Pair(long xx, long tt)
        {
            x = xx;
            t = tt;
        }

        public int compareTo(Pair o)
        {
            return x == o.x ? Long.compare(t, o.t) : Long.compare(x, o.x);
        }
    }

    void solve(FastIO io)
    {
        int n = io.nextInt();
        long[] a = new long[n];
        int[] t = new int[n];

        

        ArrayList<Long>[] needs = new ArrayList[100_001];
        for (int i = 0; i <= 100_000; i++)
            needs[i] = new ArrayList<>();

        TreeMap<Long, Integer> map = new TreeMap<>();

        for (int i = 0; i < n; i++)
            a[i] = io.nextLong();

        for (int i = 0; i < n; i++)
            t[i] = io.nextInt();

        Pair[] arr = new Pair[n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = new Pair(a[i], t[i]);
        }
        
        Arrays.sort(arr);

        Arrays.sort(a);

        PriorityQueue<Long> q = new PriorityQueue<>(Comparator.reverseOrder());

        // long curr = a[0];
        long sum = 0;
        long ans = 0;

        int j = 0;

        for (int i = 0; i < n; i++)
        {
            while (j < n && arr[j].x <= a[i])
            {
                sum += arr[j].t;
                q.add(arr[j].t);
                j++;
            }

            long curr = a[i];

            while (!q.isEmpty() && (i == n-1 || curr < a[i+1]))
            {
                sum -= q.remove();
                ans += sum;
                curr++;
            }
        }
        io.println(ans);
        
    }

    public static void main(String[] args)
    {
        FastIO io = new FastIO();

        new A().solve(io);

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

