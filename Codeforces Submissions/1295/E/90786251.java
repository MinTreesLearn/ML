import java.util.*;
import java.io.*;

public class E81 {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        int [] p = new int[n + 1];
        int [] where = new int[n + 1];
        long [] cost = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            p[i] = sc.nextInt();
            where[p[i]] = i;
        }
        for (int i = 1; i <= n; i++) cost[p[i]] = sc.nextLong();
        RangeTree seg = new RangeTree(n + 1);
        long cur = cost[p[1]];
        for (int i = 1; i < n; i++) {
            seg.update(i, i, cur);
            cur += cost[p[i + 1]];
        }
        long ans = seg.minQuery(1, n - 1);
        for (int val = 1; val <= n; val++) {
            long c = cost[val];
            if (where[val] > 1) seg.update(1, where[val] - 1, c);
            if (where[val] < n) seg.update(where[val], n - 1, -c);
            ans = Math.min(ans, seg.minQuery(1, n - 1));
        }
        out.println(ans);
        out.close();
    }

    static class RangeTree {
        private long[] max;
        private long[] min;
        private long[] lazy;
        private long[] sum;
        private int size;
        public RangeTree(int size) {
            this.size = size;
            max = new long[4*size];
            min = new long[4*size];
            sum = new long[4*size];
            lazy = new long[4*size];
        }
        public void update(int l, int r, long inc) {
            update(1, 0, size-1, l, r, inc);
        }
        private void pushDown(int index, int l, int r) {
            min[index] += lazy[index];
            max[index] += lazy[index];
            sum[index] += lazy[index] * (r-l+1);
            if(l != r) {
                lazy[2*index] += lazy[index];
                lazy[2*index+1] += lazy[index];
            }
            lazy[index] = 0;
        }
        private void pullUp(int index, int l, int r) {
            int m = (l+r)/2;
            min[index] = Math.min(evaluateMin(2*index, l, m), evaluateMin(2*index+1, m+1, r));
            max[index] = Math.max(evaluateMax(2*index, l, m), evaluateMax(2*index+1, m+1, r));
            sum[index] = evaluateSum(2*index, l, m) + evaluateSum(2*index+1, m+1, r);
        }
        private long evaluateSum(int index, int l, int r) {
            return sum[index] + (r-l+1)*lazy[index];
        }
        private long evaluateMin(int index, int l, int r) {
            return min[index] + lazy[index];
        }
        private long evaluateMax(int index, int l, int r) {
            return max[index] + lazy[index];
        }
        private void update(int index, int l, int r, int left, int right, long inc) {
            if(r < left || l > right) return;
            if(l >= left && r <= right) {
                lazy[index] += inc;
                return;
            }
            pushDown(index, l, r);
            int m = (l+r)/2;
            update(2*index, l, m, left, right, inc);
            update(2*index+1, m+1, r, left, right, inc);
            pullUp(index, l, r);
        }
        public long minQuery(int l, int r) {
            return minQuery(1, 0, size-1, l, r);
        }
        private long minQuery(int index, int l, int r, int left, int right) {
            if(r < left || l > right) return Long.MAX_VALUE;
            if(l >= left && r <= right) {
                return evaluateMin(index, l, r);
            }
            pushDown(index, l, r);
            int m = (l+r)/2;
            long ret = Long.MAX_VALUE;
            ret = Math.min(ret, minQuery(2*index, l, m, left, right));
            ret = Math.min(ret, minQuery(2*index+1, m+1, r, left, right));
            pullUp(index, l, r);
            return ret;
        }
        public long maxQuery(int l, int r) {
            return maxQuery(1, 0, size-1, l, r);
        }
        private long maxQuery(int index, int l, int r, int left, int right) {
            if(r < left || l > right) return Long.MIN_VALUE;
            if(l >= left && r <= right) {
                return evaluateMax(index, l, r);
            }
            pushDown(index, l, r);
            int m = (l+r)/2;
            long ret = Long.MIN_VALUE;
            ret = Math.max(ret, maxQuery(2*index, l, m, left, right));
            ret = Math.max(ret, maxQuery(2*index+1, m+1, r, left, right));
            pullUp(index, l, r);
            return ret;
        }
        public long sumQuery(int l, int r) {
            return sumQuery(1, 0, size-1, l, r);
        }
        private long sumQuery(int index, int l, int r, int left, int right) {
            if(r < left || l > right) return 0;
            if(l >= left && r <= right) {
                return evaluateSum(index, l, r);
            }
            pushDown(index, l, r);
            int m = (l+r)/2;
            long ret = 0;
            ret += sumQuery(2*index, l, m, left, right);
            ret += sumQuery(2*index+1, m+1, r, left, right);
            pullUp(index, l, r);
            return ret;
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