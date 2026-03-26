import java.io.*;
import java.util.*;

public class cf {

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static boolean isok(long x, long h, long k) {
        long sum = 0;
        if (h > k) {
            long t1 = h - k;
            long t = t1 * k;
            sum += (k * (k + 1)) / 2;
            sum += t - (t1 * (t1 + 1) / 2);
        } else {
            sum += (h * (h + 1)) / 2;
        }
        if (sum < x) {
            return true;
        }
        return false;
    }

    public static boolean binary_search(long[] a, long k) {
        long low = 0;
        long high = a.length - 1;
        long mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (a[(int) mid] == k) {
                return true;
            } else if (a[(int) mid] < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }

    public static long lowerbound(long a[], long ddp) {
        long low = 0;
        long high = a.length;
        long mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (a[(int) mid] == ddp) {
                return mid;
            }
            if (a[(int) mid] < ddp) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        // if(low + 1 < a.length && a[(int)low + 1] <= ddp){
        // low++;
        // }
        if (low == a.length && low != 0) {
            low--;
            return low;
        }
        if (a[(int) low] > ddp && low != 0) {
            low--;
        }
        return low;
    }

    public static long upperbound(long a[], long ddp) {
        long low = 0;
        long high = a.length;
        long mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (a[(int) mid] <= ddp) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (low == a.length) {
            return a.length - 1;
        }
        return low;
    }

    public static class pair implements Comparable<pair> {
        long w;
        long h;

        public pair(long w, long h) {
            this.w = w;
            this.h = h;
        }

        public int compareTo(pair b) {
            if (this.w != b.w)
                return (int) (this.w - b.w);
            else
                return (int) (this.h - b.h);
        }
    }

    public static class trinary {
        long a;
        long b;
        long c;

        public trinary(long a, long b, long c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    public static long lowerboundforpairs(pair a[], long pr) {
        long low = 0;
        long high = a.length;
        long mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (a[(int) mid].w <= pr) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        // if(low + 1 < a.length && a[(int)low + 1] <= ddp){
        // low++;
        // }
        // if(low == a.length && low != 0){
        // low--;
        // return low;
        // }
        // if(a[(int)low].w > pr && low != 0){
        // low--;
        // }
        return low;
    }

    public static pair[] sortpair(pair[] a) {
        Arrays.sort(a, new Comparator<pair>() {
            public int compare(pair p1, pair p2) {
                return (int) p1.w - (int) p2.w;
            }
        });
        return a;
    }

    public static boolean ispalindrome(String s) {
        long i = 0;
        long j = s.length() - 1;
        boolean is = false;
        while (i < j) {
            if (s.charAt((int) i) == s.charAt((int) j)) {
                is = true;
                i++;
                j--;
            } else {
                is = false;
                return is;
            }
        }
        return is;
    }

    public static void sort(long[] arr) {
        ArrayList<Long> a = new ArrayList<>();
        for (long i : arr) {
            a.add(i);
        }
        Collections.sort(a);
        for (int i = 0; i < a.size(); i++) {
            arr[i] = a.get(i);
        }
    }

    public static void sortForObjecttypes(Long[] arr) {
        ArrayList<Long> a = new ArrayList<>();
        for (Long i : arr) {
            a.add(i);
        }
        Collections.sort(a);
        for (int i = 0; i < a.size(); i++) {
            arr[i] = a.get(i);
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
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

        float nextFloat() {
            return Float.parseFloat(next());
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

        void readArr(int[] ar, int n) {
            for (int i = 0; i < n; i++) {
                ar[i] = nextInt();
            }
        }
    }

    public static void solve(FastReader sc, PrintWriter w) throws Exception {
        int n = sc.nextInt();
        long xi = 0;
        long yi = 0;
        pair[] p = new pair[n];
        String ans = "";
        for (int i = 0; i < n; i++) {
            long x = sc.nextLong();
            long y = sc.nextLong();
            p[i] = new pair(x, y);
        }
        Arrays.sort(p);
        // System.out.println();
        // for (pair k : p) {
        // System.out.println(k.w + " " + k.h);
        // }
        boolean is = true;
        for (int i = 1; i < n; i++) {
            if (p[i].w < p[i - 1].w) {
                is = false;
                System.out.println("NO");
                return;
            }
        }
        if (is) {
            for (int i = 1; i < n; i++) {
                if (p[i].h < p[i - 1].h) {
                    is = false;
                    System.out.println("NO");
                    return;
                }
            }
            if (is) {
                for (int i = 0; i < n; i++) {
                    if (p[i].w == xi) {
                        for (int j = 0; j < p[i].h - yi; j++) {
                            ans += 'U';
                        }
                    } else if (p[i].h == yi) {
                        for (int k = 0; k < p[i].w - xi; k++) {
                            ans += 'R';
                        }
                    } else {
                        for (int k = 0; k < p[i].w - xi; k++) {
                            ans += 'R';
                        }
                        for (int j = 0; j < p[i].h - yi; j++) {
                            ans += 'U';
                        }
                    }
                    xi = p[i].w;
                    yi = p[i].h;
                }
            } else {
                System.out.println("NO");
            }
        } else {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
        System.out.println(ans);
    }

    public static void main(String[] args) throws Exception {
        FastReader sc = new FastReader();
        PrintWriter w = new PrintWriter(System.out);
        long o = sc.nextLong();
        while (o > 0) {
            solve(sc, w);
            o--;
        }
        w.close();
    }
}