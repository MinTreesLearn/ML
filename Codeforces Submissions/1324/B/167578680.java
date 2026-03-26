import java.util.*;
import java.io.*;
 
public class practice {
 
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new PrintWriter(System.out)));
        StringBuilder sb = new StringBuilder();
 
        int t = Integer.parseInt(br.readLine());

        while (t --> 0) {

            int n = Integer.parseInt(br.readLine());
            
            StringTokenizer st = new StringTokenizer(br.readLine());
            Map<Integer, Integer> map = new HashMap<>();
            boolean ans = false;

            for (int i = 0; i < n; i++) {

                int ele = Integer.parseInt(st.nextToken());

                if (map.containsKey(ele)) {

                    int diff = i - map.get(ele);

                    if (diff > 1) ans = true;
                } else map.put(ele, i);
            }

            sb.append(ans ? "YES" : "NO").append("\n");
        }
 
        pw.println(sb.toString().trim());
        pw.close();
        br.close();
    }
}