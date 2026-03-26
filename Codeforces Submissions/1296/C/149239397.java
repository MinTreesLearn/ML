import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int t = in.nextInt();
        for (int tt = 0; tt < t; tt++) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();
            TreeMap<XY, Integer> map = new TreeMap<>();
            int start = -1, end = 1_000_000_000;;
            XY cur = new XY(0, 0);
            map.put(cur, -1);
          ///  debug(map);
            for (int i = 0; i < n; i++) {
                cur = new XY(cur.x, cur.y);
                //debug(cur);
                if (s[i] == 'U') cur.y++;
                if (s[i] == 'D') cur.y--;
                if (s[i] == 'L') cur.x--;
                if (s[i] == 'R') cur.x++;

               // debug(cur);
                int last = map.getOrDefault(cur, -100_000_000);
                if (i - last < end - start) {
                    end = i;
                    start = last;
                }
                map.put(cur, i);
            }
         /*   debug(map);
            debug(end, start);*/
            if ((end - start + 1) < 1_000_000) {
                pw.println((start + 2) + " " + (end + 1));
            } else pw.println(-1);
        }

        pw.close();
    }

    static class XY implements Comparable<XY> {
        int x, y;

        XY(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(XY o) {
            if (o.x != this.x) return Integer.compare(this.x, o.x);
            return Integer.compare(this.y, o.y);
        }

        @Override
        public String toString() {
            return "[" +
                    "x:" + x +
                    ", y:" + y +
                    ']';
        }
    }

    static void debug(Object... obj) {
        System.err.println(Arrays.deepToString(obj));
    }
}
