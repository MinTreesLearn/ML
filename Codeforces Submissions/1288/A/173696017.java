// Jai Shree Ram ⛳⛳⛳
// Jai Bajrang Bali
// Jai Saraswati maa
// Har Har Mahadev
// Thanks Kalash Shah :)

import java.math.BigInteger;
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Character.isUpperCase;

public class C {
    static FastScanner sn = new FastScanner();

    public static void main(String[] args) {
        int T = sn.nextInt();
        while (T-- > 0)
            solve();
    }

    public static void solve() {
        int n = sn.nextInt();
        int d = sn.nextInt();
        for (int i = 0; i <= 1000000; i++) {
            if (i + (d + i) / (i + 1) <= n) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }


    //----------------------------------------------------------------------------------//
    public static void mergesort(long[] arr, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }

    static long getFirstSetBitPos(long n) {
        return (long) ((Math.log10(n & -n)) / Math.log10(2)) + 1;
    }

    static int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    static class Pair implements Comparable<Pair> {
        int ind;
        int ch;

        Pair(int a, int ch) {
            this.ind = a;
            this.ch = ch;
        }

        public int compareTo(Pair o) {
            if (this.ch == o.ch) {
                return this.ind - o.ind;
            }
            return this.ch - o.ch;
        }

        public String toString() {
            return "";
        }
    }

    static int countSetBits(long n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    public static void Merge(long[] arr, int l, int mid, int r) {
        long[] B = new long[r - l + 1];
        int i = l;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                B[k++] = arr[i++];
            } else {
                B[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            B[k++] = arr[i++];
        }
        while (j <= r) {
            B[k++] = arr[j++];
        }

        for (int i1 = 0, j1 = l; i1 < B.length; i1++, j1++) {
            arr[j1] = B[i1];
        }
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        char nextChar() {
            return next().charAt(0);
        }

        long[] readArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }

        int[] scan(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        void print(int[] a) {
            for (int j : a) {
                System.out.print(j + " ");
            }
        }

        void printl(long[] a) {
            for (long j : a) {
                System.out.print(j + " ");
            }
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    static class Debug {
        public static void debug(long a) {
            System.out.println("--> " + a);
        }

        public static void debug(long a, long b) {
            System.out.println("--> " + a + " + " + b);
        }

        public static void debug(char a, char b) {
            System.out.println("--> " + a + " + " + b);
        }

        public static void debug(int[] array) {
            System.out.print("Array--> ");
            System.out.println(Arrays.toString(array));
        }

        public static void debug(char[] array) {
            System.out.print("Array--> ");
            System.out.println(Arrays.toString(array));
        }

        public static void debug(HashMap<Integer, Integer> map) {
            System.out.print("Map--> " + map.toString());
        }
    }
}