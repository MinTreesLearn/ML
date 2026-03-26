import java.io.*;
import java.util.*;

public class tank {

    static final FastScanner fs = new FastScanner();

    //static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while(t-- > 0) run_case();

        //out.close();
    }

    static void run_case() {
        int n = fs.nextInt();
        Integer[][] a = new Integer[n][2];

        for (int i = 0; i < n; i++) {
            a[i][0] = fs.nextInt();
        }

        for (int i = 0; i < n; i++) {
            a[i][1] = fs.nextInt();
        }

        Arrays.sort(a, new comp());

        PriorityQueue<Integer> pq = new PriorityQueue<>(new comp2());

        int i = 0;

        long ans = 0, sum = 0, cur = 0;

        while(!pq.isEmpty() || i < n) {
            if(pq.isEmpty()) {
                pq.offer(a[i][1]);
                sum = a[i][1];
                cur = a[i][0];

                i++;

                for (; i < n && a[i][0].equals(a[i - 1][0]); i++) {
                    pq.offer(a[i][1]);
                    sum += a[i][1];
                }
            }

            sum -= pq.poll();
            ans += sum;

            cur++;

            while(i < n && a[i][0] == cur) {
                sum += a[i][1];
                pq.offer(a[i][1]);
                i++;
            }
        }

        System.out.println(ans);
    }

    static class comp implements Comparator<Integer[]> {
        @Override
        public int compare(Integer[] o1, Integer[] o2) {
            if(o1[0] > o2[0]) return 1;
            else if(o1[0].equals(o2[0])) {
                if(o1[1] < o2[1]) return 1;
                else if(o1[1].equals(o2[1])) return 0;
            }
            return -1;
        }
    }

    static class comp2 implements Comparator<Integer> {
        @Override
        public int compare(Integer o1, Integer o2) {
            if(o1 < o2) return 1;
            else if(o1.equals(o2)) return 0;
            return -1;
        }
    }

    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        String nextLine(){
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return "";
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}