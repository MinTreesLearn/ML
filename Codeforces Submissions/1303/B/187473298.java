

import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {

    static int MAX = 31630;
    static boolean[] isPrime = new boolean[MAX];
    static List<Integer> primes = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        FastReader fastReader = new FastReader();
        int t = fastReader.nextInt();


        while (t-- > 0) {
            int n =fastReader.nextInt();
            int g=fastReader.nextInt();
            int b = fastReader.nextInt();

           
            int goodDays =(int) Math.ceil((1.0*n)/2);
            long totalDays = (long) goodDays / g * (g+b) ;
            int remainder =goodDays%g;
            totalDays = remainder==0?totalDays-b:totalDays+remainder;

            System.out.println(Math.max(totalDays,n));


        }
    }


    private static void solve(int t) {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        for (int prime : primes) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] % prime == 0) {
                    count++;
                    if (count > 1) {
                        out.println("YES");
                        return;
                    }
                    while (arr[i] % prime == 0) {
                        arr[i] /= prime;
                    }
                }
            }
        }
        HashSet<Integer> seen = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                continue;
            }
            if (seen.contains(arr[i])) {
                out.println("YES");
                return;
            }
            seen.add(arr[i]);
        }

        out.println("NO");
    }

    private static void sieve() {
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < MAX; i++) {
            if (isPrime[i]) {
                primes.add(i);
                for (int j = 2 * i; j < MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }


    public static FastReader sc;
    public static PrintWriter out;

    static class FastReader {
        BufferedReader br;
        StringTokenizer str;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (str == null || !str.hasMoreElements()) {
                try {
                    str = new StringTokenizer(br.readLine());
                } catch (IOException lastMonthOfVacation) {
                    lastMonthOfVacation.printStackTrace();
                }

            }
            return str.nextToken();
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException lastMonthOfVacation) {
                lastMonthOfVacation.printStackTrace();
            }
            return str;
        }
    }
}