import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class test {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringBuilder result = new StringBuilder();
            if (n % 2 == 0) {
                result.append("1");
                n -= 2;
            } else {
                result.append("7");
                n -= 3;
            }

            while (n > 0) {
                result.append("1");
                n -= 2;
            }

            pw.println(result.toString());
        }

        pw.flush();
        pw.close();
        br.close();
    }
}