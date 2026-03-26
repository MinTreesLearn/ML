
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader s = new InputReader();
        PrintWriter w = new PrintWriter(System.out);
        int T = s.nextInt();
        while(T-->0){
            int n = s.nextInt();
            char[] c = s.next().toCharArray();
            int[] ans = new int[n];
            int num = n, last = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == n - 1 || c[i] == '>')
                {
                    for (int j = i; j >= last; j--)
                        ans[j] = num--;
                    last = i + 1;
                }
            }
            for (int i = 0; i < n; i++) w.write(ans[i]+" ");
            w.println();
            num = 1;
            last = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == n - 1 || c[i] == '<')
                {
                    for (int j = i; j >= last; j--)
                        ans[j] = num++;
                    last = i + 1;
                }
            }
            for (int i = 0; i < n; i++) w.write(ans[i]+" ");
            w.println();
        }
        w.flush();
    }
}
class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;


    public InputReader() {
        reader = new BufferedReader(new InputStreamReader(System.in), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}