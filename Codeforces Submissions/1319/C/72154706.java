import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        String s = sc.next();
        int size = s.length();
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            char max = 'a' - 1;
            int index = -1;
            for (int j = 0; j < s.length(); j++) {
                if ((int) max < (int) s.charAt(j) && ((j > 0 && s.charAt(j - 1) + 1 == s.charAt(j)) || (j < s.length() - 1 && s.charAt(j + 1) + 1 == s.charAt(j)))) {
                    index = j;
                    max = s.charAt(j);
                }
            }
            if(index == -1)
                break;
            String buf = "";
            for (int j = 0; j < s.length(); j++) {
                if(j == index)
                    continue;
                buf += s.charAt(j);
            }
            s = buf;
            cnt++;
        }
        pw.print(cnt);
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
