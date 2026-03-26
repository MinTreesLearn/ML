import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.Math.pow;

public class Main {

    void run() throws IOException {
        int n = nextInt();
        int[][] otr = new int[n][4];
        touple[] event = new touple[n * 2];
        for (int i = 0; i < 2 * n; i += 2) {
            for (int j = 0; j < 4; j++) {
                otr[i / 2][j] = nextInt();
            }
            event[i] = new touple(otr[i / 2][0], 0, i / 2);
            event[i + 1] = new touple(otr[i / 2][1], 1, i / 2);
        }
        Arrays.sort(event);
        int[] cnt_for_a = new int[n];
        int ended = 0;
        int not_started = n;
        Arrays.fill(cnt_for_a, n - 1);
        for (int i = 0; i < event.length; i++) {
            int num = event[i].num;
            if (event[i].type == 0) {
                cnt_for_a[num] -= ended;
                not_started--;
            } else {
                cnt_for_a[num] -= not_started;
                ended++;
            }
        }
        event = new touple[n * 2];
        for (int i = 0; i < 2 * n; i += 2) {
            event[i] = new touple(otr[i / 2][2], 0, i / 2);
            event[i + 1] = new touple(otr[i / 2][3], 1, i / 2);
        }
        Arrays.sort(event);
        int[] cnt_for_b = new int[n];
        ended = 0;
        not_started = n;
        Arrays.fill(cnt_for_b, n - 1);
        for (int i = 0; i < event.length; i++) {
            int num = event[i].num;
            if (event[i].type == 0) {
                cnt_for_b[num] -= ended;
                not_started--;
            } else {
                cnt_for_b[num] -= not_started;
                ended++;
            }
        }
        for (int i = 0; i < cnt_for_a.length; i++) {
            if(cnt_for_a[i] != cnt_for_b[i]){
                pw.println("NO");
                pw.close();
                return;
            }
        }
        pw.println("YES");
        pw.close();
    }

    class touple implements Comparable<touple> {
        int x, type, num;

        public touple(int x, int type, int num) {
            this.x = x;
            this.type = type;
            this.num = num;
        }

        @Override
        public int compareTo(touple o) {
            if (o.x == this.x) return -Integer.compare(o.type, this.type);
            return -Integer.compare(o.x, this.x);
        }
    }

    class point implements Comparable<point> {
        int x, num;

        public point(int a, int b) {
            x = a;
            num = b;
        }

        @Override
        public int compareTo(point o) {
            return -Long.compare(o.x, this.x);
        }

    }

    long mod = (long) 1e9 + 7;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    //BufferedReader br = new BufferedReader(new FileReader("cond.in"));

    StringTokenizer st = new StringTokenizer("");
    PrintWriter pw = new PrintWriter(System.out);
    //PrintWriter pw = new PrintWriter("cond.out");

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public Main() throws FileNotFoundException {
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}