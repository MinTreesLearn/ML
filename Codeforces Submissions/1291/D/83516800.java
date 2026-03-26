import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class IrreducibleAnagrams {

    public static void main(String[] args) throws IOException{
        new IrreducibleAnagrams().solve();
    }

    public void solve() throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        char[] seq = f.readLine().toCharArray();
        int q = Integer.parseInt(f.readLine());
        int[][] prefLetters = new int[seq.length][26];
        prefLetters[0][seq[0] - 'a']++;
        for (int i = 1; i < seq.length; i++) {
            for (int j = 0; j < 26; j++) {
                prefLetters[i][j] = prefLetters[i - 1][j];
            }
            prefLetters[i][seq[i] - 'a']++;
        }
        for (int q1 = 0; q1 < q; q1++) {
            StringTokenizer tokenizer = new StringTokenizer(f.readLine());
            int l = Integer.parseInt(tokenizer.nextToken()) - 1;
            int r = Integer.parseInt(tokenizer.nextToken()) - 1;
            if (l == r) {
                out.println("Yes");
                continue;
            }
            if (seq[l] != seq[r]) {
                out.println("Yes");
                continue;
            }
            int numOfDiff = 0;
            for (int i = 0; i < 26; i++) {
                int letters = prefLetters[r][i];
                if (l != 0) {
                    letters -= prefLetters[l - 1][i];
                }
                if (letters > 0) numOfDiff++;
            }
            if (numOfDiff > 2) {
                out.println("Yes");
            } else {
                out.println("No");
            }
        }

        out.close();
    }
}
