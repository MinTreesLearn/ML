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

    // public static class pair implements Comparable<pair> {
    // long w;
    // long h;

    // public pair(long w, long h) {
    // this.w = w;
    // this.h = h;
    // }

    // public int compareTo(pair b) {
    // if (this.w != b.w)
    // return (int) (this.w - b.w);
    // else
    // return (int) (this.h - b.h);
    // }
    // }

    public static class pair {
        long w;
        long h;

        public pair(long w, long h) {
            this.w = w;
            this.h = h;
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

    public static void sortForObjecttypes(pair[] arr) {
        ArrayList<pair> a = new ArrayList<>();
        for (pair i : arr) {
            a.add(i);
        }
        Collections.sort(a, new Comparator<pair>() {
            @Override
            public int compare(pair a, pair b) {

                return (int) (a.h - b.h);
            }
        });
        for (int i = 0; i < a.size(); i++) {
            arr[i] = a.get(i);
        }
    }

    public static long power(long base, long pow, long mod) {
        long result = base;
        long temp = 1;
        while (pow > 1) {
            if (pow % 2 == 0) {
                result = ((result % mod) * (result % mod)) % mod;
                pow /= 2;
            } else {
                temp = temp * base;
                pow--;
            }
        }
        result = ((result % mod) * (temp % mod));
        // System.out.println(result);
        return result;
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
        int m = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int id[] = new int[n];
        for (int i = 0; i < m; i++) {
            int t = sc.nextInt();
            id[t - 1] = 1;
        }
        boolean is = false;
        while (true) {
            is = false;
            for (int i = 0; i < n - 1; i++) {
                if (id[i] == 1 && a[i] > a[i + 1]) {
                    int temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                    is = true;
                }
            }
            if (!is) {
                break;
            }
        }
        is = true;
        for (int i = 0; i < n - 1; i++) {
            is &= a[i] <= a[i + 1];
        }
        if (is) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
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