/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."

                        Just have Patience + 1...

*/








import java.util.*;
import java.lang.*;
import java.io.*;


public class Solution {

    static class FenwickTree {
        long[] tree;
        int n;

        FenwickTree(int n) {
            this.n = n;
            tree = new long[n + 1];
        }

        public void update(int index, int add) {
            index++;
            while (index <= n) {
                tree[index] += add;
                index += index & -index;
            }
        }

        public long query(int start, int end) {
            return prefixQuery(end) - prefixQuery(start - 1);
        }

        private long prefixQuery(int index) {
            index++;
            long sum = 0;
            while (index > 0) {
                sum += tree[index];
                index -= index & -index;
            }
            return sum;
        }
    }

    static boolean sortBySpeed = false;

    static class MovingPoint implements Comparable<MovingPoint> {
        int position;
        int speed;

        MovingPoint(int position, int speed) {
            this.position = position;
            this.speed = speed;
        }

        public int compareTo(MovingPoint m) {
            if (sortBySpeed) {
                return Integer.compare(speed, m.speed);
            }
            return Integer.compare(position, m.position);
        }
    }

    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = 1;
        for (int t = 1; t <= test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt();

        MovingPoint[] movingPoints = new MovingPoint[n];
        for (int i = 0; i < n; i++) {
            movingPoints[i] = new MovingPoint(0, 0);
        }

        for (int i = 0; i < n; i++) {
            movingPoints[i].position = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            movingPoints[i].speed = sc.nextInt();
        }

        sortBySpeed = true;
        Arrays.sort(movingPoints);

        // compress speeds so that we can fit speeds in fenwick tree
        int lastSpeed = movingPoints[0].speed;
        movingPoints[0].speed = 0;
        for (int i = 1; i < n; i++) {
            if (movingPoints[i].speed == lastSpeed) {
                movingPoints[i].speed = movingPoints[i - 1].speed;
            }else {
                lastSpeed = movingPoints[i].speed;
                movingPoints[i].speed = movingPoints[i - 1].speed + 1;
            }
        }

        sortBySpeed = false;
        Arrays.sort(movingPoints);

        /*
            Now count minimum distance of each moving pairs,
            so for pair i, j assuming i < j,
            if speed of i <= speed of j, then the minimum distance we could get is the initial distance between these two moving points.
            else, point i can intersect at some moment of time with point j, and so minimum distance would be 0.

            So, total sum of distances would be like :
            (position_j - position_i1) + (position_j - position_i2) + .... = (count of points having speed <= speed_j) * position_j - (sum of positions having speed <= speed_j).

         */

        FenwickTree count = new FenwickTree(n);
        FenwickTree sum = new FenwickTree(n);

        long totalSumOfDistances = 0;
        for (MovingPoint movingPoint : movingPoints) {
            int speed = movingPoint.speed;
            int position = movingPoint.position;

            totalSumOfDistances += count.prefixQuery(speed) * position - sum.prefixQuery(speed);

            sum.update(speed, position);
            count.update(speed, 1);
        }

        out.println(totalSumOfDistances);
    }


    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer str;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (str == null || !str.hasMoreElements())
            {
                try
                {
                    str = new StringTokenizer(br.readLine());
                }
                catch (IOException  lastMonthOfVacation)
                {
                    lastMonthOfVacation.printStackTrace();
                }
            }
            return str.nextToken();
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

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException lastMonthOfVacation)
            {
                lastMonthOfVacation.printStackTrace();
            }
            return str;
        }
    }

}