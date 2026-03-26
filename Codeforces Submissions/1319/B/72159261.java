import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        long[] b = new long[n];
        for (int i = 0; i < n; i++)
            b[i] = sc.nextLong() - i;
        TreeMap<Long, Long> sums = new TreeMap<>();
        for (int i = 0; i < n; i++)
            sums.put(b[i], sums.getOrDefault(b[i], 0L) + b[i] + i);
        long maxSum = 0;
        for (long a : sums.values())
            maxSum = max(maxSum, a);
        pw.print(maxSum);
        pw.close();
    }


    public static boolean isVowel(char a) {
        return a == 'a' || a == 'e' || a == 'u' || a == 'o' || a == 'y';
    }

    public static long binPow(long a, int n) {
        long p = a;
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res *= p;
            p *= p;
            n /= 2;
        }
        return res;
    }

    public static int gcd(int a, int b) {
        if (a == 0 || b == 0)
            return a + b;
        return gcd(b % a, a);
    }

    public static long gcd(long a, long b) {
        if (a == 0 || b == 0)
            return a + b;
        return gcd(b % a, a);
    }
}

class chr {
    char a;
    int index;

    public chr(char a, int index) {
        this.a = a;
        this.index = index;
    }
}

class chrComp implements Comparator<chr> {
    public int compare(chr o1, chr o2) {
        return Character.compare(o1.a, o2.a);
    }
}

class FastScanner {
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public FastScanner(InputStream inputStream) {
        br = new BufferedReader(new InputStreamReader(inputStream));
    }

    public FastScanner(String fileName) throws FileNotFoundException {
        br = new BufferedReader(new FileReader(fileName));
    }

    public boolean hasNext() {
        try {
            while (!st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        hasNext();
        return st.nextToken();
    }
}
