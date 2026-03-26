import java.util.*;
import java.io.*;
 
public class practice {
 
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new PrintWriter(System.out)));
        StringBuilder sb = new StringBuilder();
 
        int t = Integer.parseInt(br.readLine());

        while (t --> 0) {

            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < k; i++) set.add(Integer.parseInt(st.nextToken()));

            int min1 = Integer.MAX_VALUE;
            for (int i = s; i > 0; i--) {

                if (!set.contains(i)) {

                    min1 = s - i;
                    break;
                }
            }

            int min2 = Integer.MAX_VALUE;
            for (int i = s; i <= n; i++) {

                if (!set.contains(i)) {

                    min2 = i - s;
                    break;
                }
            }

            sb.append(Math.min(min1, min2)).append("\n");
        }
        
        pw.println(sb.toString().trim());
        pw.close();
        br.close();
    }
}