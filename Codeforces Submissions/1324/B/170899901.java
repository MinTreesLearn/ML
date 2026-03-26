import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class YetAnotherPalindromeProblem {
    static BufferedReader br;
    static PrintWriter pw;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            if (testCase()) pw.println("YES");
            else pw.println("NO");
        }

        pw.close();
    }

    private static boolean testCase() throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int item = arr[i];
            Integer prev = map.get(item);
            if (prev != null) {
                if (i - prev > 1) return true;
                else continue;
            }
            map.put(item, i);
        }

        return false;
    }
}
