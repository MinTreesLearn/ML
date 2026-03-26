import java.io.*;
import java.util.*;

public class Run {

    public static int mod = 1000000007;
    public static PrintWriter out = new PrintWriter(System.out);
    public static boolean testing = false;
    public static FastIO io;
    public static String input_file = "./input.txt";

    static {
        try {
            io = new FastIO();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static int[] sort(int[] arr) {
        List<Integer> nums = new ArrayList<>();
        for (int el : arr) nums.add(el);
        Collections.sort(nums);
        int[] res = new int[arr.length];
        for (int i = 0; i < arr.length; i++) res[i] = nums.get(i);
        return res;
    }


    public static long[] sort(long[] arr) {
        List<Long> nums = new ArrayList<>();
        for (long el : arr) nums.add(el);
        Collections.sort(nums);
        long[] res = new long[arr.length];
        for (int i = 0; i < arr.length; i++) res[i] = nums.get(i);
        return res;
    }


    public static void reverse(int[] arr, int i, int j) {
        while (i < j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            ++i;
            --j;
        }
    }

    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static int lowerBound(long[] arr, long x) {
        int l = -1;
        int r = arr.length;
        while (r > l + 1) {
            int m = l + (r - l) / 2;
            if (arr[m] <= x) l = m;
            else r = m;
        }
        return Math.max(0, l);
    }

    public static int upperBound(long[] arr, long x) {
        int l = -1;
        int r = arr.length;
        while (r > l + 1) {
            int m = l + (r - l) / 2;
            if (arr[m] >= x) r = m;
            else l = m;
        }
        return Math.min(arr.length - 1, r);
    }

    public static int log2(int a) {
        return (int) (Math.log(a) / Math.log(2));
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int n = io.nextInt();
        char[] arr = io.next().toCharArray();

        int ans = 0;
        int curr = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == '(') ++curr;
            else --curr;
            if (curr < 0) ++ans;
            if (curr == 0 && prev < 0) ++ans;
            prev = curr;
        }
        if (curr != 0) ans = -1;
        out.write(ans + "\n");
        out.close();
    }

    static class CC implements Comparator<Pair> {
        public int compare(Pair o1, Pair o2) {
            if (o1.first == o2.first) return o1.second - o2.second;
            return o1.first - o2.first;
        }
    }

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "first=" + first +
                    ", second=" + second +
                    '}';
        }
    }

    static class FastIO {
        InputStreamReader s = new InputStreamReader(testing ? new FileInputStream(input_file) : System.in);
        BufferedReader br = new BufferedReader(s);
        StringTokenizer st = new StringTokenizer("");

        FastIO() throws FileNotFoundException {
        }

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

}
