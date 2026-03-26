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
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            long tot = 0;

            for (long i = 9; i <= b; i = (i * 10) + 9) tot += a;

            sb.append(tot).append("\n");
        }
 
        pw.println(sb.toString().trim());
        pw.close();
        br.close();
    }
}