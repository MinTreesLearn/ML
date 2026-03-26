import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class AirConditioner {
    static BufferedReader br;
    static PrintWriter pw;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) test();
        pw.close();
    }

    static void test() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int temp = Integer.parseInt(st.nextToken());

        ArrayList<Customer> c = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            c.add(new Customer(t, l, r));
        }
        c.sort(Comparator.comparingInt(o -> o.t));
        long t = 0, l = temp, r = temp;
        for (int i = 0; i < n; i++) {
            long time = c.get(i).t - t;
            Customer curr = c.get(i);
            if (r + time >= curr.l && l - time <= curr.r) {
                r = Math.min(r + time, curr.r);
                l = Math.max(l - time, curr.l);
            } else {
                System.out.println("NO");
                return;
            }
            t = curr.t;
        }
        System.out.println("YES");
    }

    static class Customer {
        public int t, l, r;

        public Customer(int t, int l, int r) {
            this.t = t;
            this.l = l;
            this.r = r;
        }
    }
}