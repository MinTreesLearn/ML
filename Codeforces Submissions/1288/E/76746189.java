import java.util.*;
import java.io.*;
public class E80
{
    public static void main(String [] args)
    {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt(); int m = sc.nextInt(); int [] a = new int [m];
        for (int i = 0; i < m; i++) a[i] = sc.nextInt();
        FenwickTree bit = new FenwickTree(m + 1); int [] max = new int [n+1]; int [] last = new int [n+1];
        for (int i = 1; i <= n; i++) max[i] = i;
        Arrays.fill(last, -1); FenwickTree bit2 = new FenwickTree(n + 1);
        Map<Integer, Query> map = new HashMap<>();
        for (int i = 0; i < m; i++) {
            if (last[a[i]] != -1) {
                map.put(i, new Query(last[a[i]], i));
            } else {
                map.put(i, new Query(-1, i));
            }
            last[a[i]] = i;
        }
        ArrayList<Query> q = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            q.add(new Query(last[i], m));
        }
        last = new int [n+1]; Arrays.fill(last, -1);
        for (int i = 0; i < m; i++) {
            int start = map.get(i).start; int end = map.get(i).end;
            if (start == -1) {
                int query = bit2.sum(a[end]);
                max[a[end]] = Math.max(max[a[end]], a[end] + bit2.sum(n) - query);
                bit2.update(a[end], 1); bit.update(i + 1, 1);
                last[a[i]] = i;
            } else {
                if (start + 1 == end) {
                    bit.update(start + 1, -1);
                    bit.update(end + 1, 1); last[a[end]] = i;
                    continue;
                }
                int query = bit.rangeSum(start + 1, end + 1);
                max[a[end]] = Math.max(max[a[end]], query); bit.update(start + 1, -1);
                bit.update(end + 1, 1); last[a[end]] = i;
            }
        }
        for (int i = 0; i < q.size(); i++) {
            int start = q.get(i).start; int end = q.get(i).end;
            if (start != -1) {
                int query = bit.rangeSum(start + 1, m);
                max[a[start]] = Math.max(max[a[start]], query);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (last[i] == -1) {
                int query = bit2.sum(i);
                max[i] = Math.max(max[i], i + bit2.sum(n) - query);
            }
        }
        int [] min = new int [n+1]; for (int i = 1; i <= n; i++) min[i] = last[i] == -1 ? i : 1;
        for (int i = 1; i <= n; i++) out.println(min[i] + " " + max[i]);
        out.close();
    }

    static class Query {
        int start; int end;
        Query(int start, int end) {
            this.start = start; this.end = end;
        }
    }

    static class FenwickTree
    {
        int size;
        int [] table;

        FenwickTree(int size)
        {
            table = new int [size];
            this.size = size;
        }

        void init(int [] nums)
        {
            for (int i = 1; i < nums.length; i++)
            {
                update(i, nums[i]);
            }
        }

        void update(int i, int delta)
        {
            while (i < size)
            {
                table[i] += delta;
                i += Integer.lowestOneBit(i);
            }
        }

        int sum(int i)
        {
            int sum = 0;
            while (i > 0)
            {
                sum += table[i];
                i -= Integer.lowestOneBit(i);
            }
            return sum;
        }

        int rangeSum(int i, int j)
        {
            return sum(j) - sum(i - 1);
        }
    }




    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
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

        String nextLine(){
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