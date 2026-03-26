import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ARecommendations solver = new ARecommendations();
        solver.solve(1, in, out);
        out.close();
    }

    static class ARecommendations {
        public void solve(int testNumber, Scanner sc, PrintWriter pw) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            int[] time = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();
            for (int i = 0; i < n; i++)
                time[i] = sc.nextInt();
            Integer[] sort = new Integer[n];
            for (int i = 0; i < n; i++)
                sort[i] = i;
            Arrays.sort(sort, (a, b) -> arr[a] - arr[b]);
            PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
            int last = arr[sort[0]];
            long ans = 0;
            long cur = 0;
            for (int i = 0; i < n; i++) {
                if (last != arr[sort[i]]) {
                    while (last < arr[sort[i]] && !pq.isEmpty()) {
                        cur -= pq.poll();
                        ans += cur;
                        last++;
                    }
                }
                pq.add(time[sort[i]]);
                cur += time[sort[i]];
                last = arr[sort[i]];
            }
            while (!pq.isEmpty()) {
                cur -= pq.poll();
                ans += cur;
            }
            pw.println(ans);
        }

    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

