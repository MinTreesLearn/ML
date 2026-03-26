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
            int d = Integer.parseInt(st.nextToken());

            if (d <= n) sb.append("Yes");
            else {

                int low = 0;
                int high = n;
                boolean flag = false;

                while (low <= high && !flag) {

                    int mid1 = low + (high - low) / 3;
                    int mid2 = high - (high - low) / 3;

                    int temp1 = mid1 + (int) Math.ceil((double) d / (mid1 + 1));
                    int temp2 = mid2 + (int) Math.ceil((double) d / (mid2 + 1));

                    if (temp2 <= n || temp1 <= n) flag = true;
                    else {

                        low = mid1 + 1;
                        high = mid2 - 1;
                    }
                }

                sb.append(flag ? "Yes" : "No");
            }

            sb.append("\n");
        }
 
        pw.println(sb.toString().trim());
        pw.close();
        br.close();
    }
}