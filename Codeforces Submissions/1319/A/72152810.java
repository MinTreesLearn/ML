import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[] r = new int[n];
        int[]b  = new int[n];
        int cntB = 0;
        int cntR = 0;
        for (int i = 0; i < n; i++)
            r[i] = sc.  nextInt();
        for (int i = 0; i < n; i++)
            b[i] = sc.nextInt();
        for (int i = 0; i < n; i++) {
            if(r[i] + b[i] == 2)
                continue;
            if(r[i] == 1)
                cntR++;
            if(b[i] == 1)
                cntB++;
        }
        if (cntR == 0)
            pw.print("-1");
        else
            pw.print((cntB) / cntR + 1);
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
