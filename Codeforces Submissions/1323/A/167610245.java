import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        r.init(System.in);

        int t = r.nextInt();
        while (t-- > 0) {
            int n = r.nextInt();
            int[] arr = new int[n];
            int even, odd;
            even = odd = 0;
            int[] ans = new int[2];
            for (int  i = 0; i < n; i++) arr[i] = r.nextInt();

            for (int  i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    even++;
                    ans[0] = i + 1;
                    break;
                }else{
                    ans[odd] = i + 1;
                    odd++;
                    if (odd == 2) break;
                }
            }
            if (even != 0){
                System.out.println(1);
                System.out.println(ans[0]);
            }else if (odd == 2){
                System.out.println(2);
                System.out.println(ans[0] + " " + ans[1]);
            }else System.out.println(-1);
        }
    }
}

class r {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer
                = new StringTokenizer("");
    }

    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

