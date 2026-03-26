import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class test {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer tokenizer = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(tokenizer.nextToken());
            int b = Integer.parseInt(tokenizer.nextToken());
            int c = Integer.parseInt(tokenizer.nextToken());
            int temp = 0;

            if (a < b) {
                temp = b;
                b = a;
                a = temp;
            }
            if (a < c) {
                temp = c;
                c = a;
                a = temp;
            }
            if (b < c) {
                temp = c;
                c = b;
                b = temp;
            }

            int result = 0;

            if (a != 0) {
                result++;
                a--;
            }
            if (b != 0) {
                result++;
                b--;
            }
            if (c != 0) {
                result++;
                c--;
            }
            if (a != 0 && b != 0) {
                result++;
                a--;
                b--;
            }
            if (a != 0 && c != 0) {
                result++;
                a--;
                c--;
            }
            if (c != 0 && b != 0) {
                result++;
                c--;
                b--;
            }
            if (a != 0 && b != 0 && c != 0) {
                result++;
                a--;
                b--;
                c--;
            }

            pw.println(result);
        }

        pw.flush();
        pw.close();
        br.close();
    }
}