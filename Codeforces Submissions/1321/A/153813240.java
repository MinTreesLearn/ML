import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class test {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        StringTokenizer tokenizer = new StringTokenizer(br.readLine());
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = Integer.parseInt(tokenizer.nextToken());
        }
        tokenizer = new StringTokenizer(br.readLine());
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(tokenizer.nextToken());
        }

        pw.println(solve(r, b, n));
        pw.flush();
        pw.close();
        br.close();
    }

    public static int solve(int[] r, int[] b, int n) {
        int rw = 0;
        int bw = 0;
        for (int i = 0; i < n; i++) {
            if (r[i] == 1 && b[i] == 0)
                rw++;
            else if (r[i] == 0 && b[i] == 1)
                bw++;
        }

        if (rw == 0)
            return -1;
        if (rw > bw)
            return 1;

        return (int) Math.ceil((double) (bw + 1) / (double) rw);
    }
}