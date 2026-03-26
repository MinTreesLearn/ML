import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.*;

public class Solution {


    // n people including me
    // arr of size n

    // some order of people
    // every min person at from polls first or last

    // i'm standing in position M
    // *before the process start*, I can choose K different people in the line
    // and choose whether they take first or last

    // i want the greatest value i can take

    public static void main(String[] args) {

        FastScanner fs = new FastScanner();
        PrintStream out = System.out;

        int T = fs.nextInt();

        for (int tt = 1; tt <= T; tt++){
            int n = fs.nextInt();
            int m = fs.nextInt(); // people in front of me
            int k = fs.nextInt(); // people i can change

            int[] arr = fs.readArray(n);

            m -= 1;
            k = Math.min(m, k);


            // i want the choices such that I have the worst results

            // 4 2
            // 2 9 2 3 8 5

            // 2 9 2 3 8 5

            // x x x
            // x x x x | n n n n n n n | x x x x


            int max = Integer.MIN_VALUE;

            for (int i = 0; i <= k; i++) {

                int right = n - k + i - 1;
                int people = m - k;
                int min = Integer.MAX_VALUE;

                for (int j = 0; j <= people; j++) {
                    int idx = i + j;
                    int idx2 = right - people + j;
                    int local = Math.max(arr[idx], arr[idx2]);
                    min = Math.min(min, local);
                }
                max = Math.max(max, min);
            }
            out.println(max);
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

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }


}