import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String s = input.readLine();

        int[][] count = new int[s.length() + 1][26];

        for (int i = 0; i < s.length(); ++i) {
            count[i + 1] = count[i].clone();
            count[i + 1][s.charAt(i) - 'a'] += 1;
        }

        int q = Integer.parseInt((new StringTokenizer(input.readLine())).nextToken());
        while (q-- != 0) {
            StringTokenizer tokenizer = new StringTokenizer(input.readLine());
            int l = Integer.parseInt(tokenizer.nextToken()) - 1, r = Integer.parseInt(tokenizer.nextToken()) - 1;
            int distinct = 0;
            for (int i = 0; i < 26; ++i) {
                distinct += (count[r + 1][i] != count[l][i] ? 1 : 0);
            }
            if (l != r && s.charAt(l) == s.charAt(r) && distinct < 3) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
            }
        }
    }
}
