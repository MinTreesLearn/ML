import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class YetAnotherMemeProblem {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        for (int i= 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            String bS = Integer.toString(b);
            long nines = bS.length() - 1;
            int count = 0;
            for (int j = 0; j < bS.length(); j++) {
                if (bS.charAt(j) == '9') count++;
            }
            if (count == bS.length()) nines++;
            pw.println(a * nines);
        }

        pw.close();
    }
}