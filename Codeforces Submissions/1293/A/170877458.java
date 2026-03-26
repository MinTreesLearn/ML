import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;

// ConneR and the A.R.C Markland-N
public class ARCMarklandN {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int curr = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());

            TreeSet<Integer> set = new TreeSet<>();
            st = new StringTokenizer(br.readLine());
            boolean has = true;
            for (int j = 0; j < x; j++) {
                int block = Integer.parseInt(st.nextToken());
                set.add(block);
                if (block == curr) has = false;
            }
            if (has) {
                pw.println(0);
                continue;
            }
            int left = curr, right = curr;
            boolean foundLeft = true, foundRight = true;
            while (left >= 1 && set.contains(left)) {
                left--;
                if (left < 1) {
                    foundLeft = false;
                    break;
                }
            }
            while (right <= n && set.contains(right)) {
                right++;
                if (right > n) {
                    foundRight = false;
                    break;
                }
            }
            if (!foundLeft) left = Integer.MAX_VALUE;
            if (!foundRight) right = Integer.MAX_VALUE;

            pw.println(Math.min(Math.abs(left - curr), Math.abs(right - curr)));
        }

        pw.close();
    }
}
