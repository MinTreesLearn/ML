import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class StringColoring {

    public static void main(String[] args) throws IOException {
        new StringColoring().solve();
    }

    public void solve() throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(f.readLine());
        char[] seq = f.readLine().toCharArray();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = seq[i] - 'a';
        }
        seq = null;

        int[] color = new int[n];
        int[][] maxByColor = new int[n][26];
        for (int i = 0; i < n; i++) {
            color[i] = maxByColor[i][values[i]] + 1;
            if (i != n - 1) {
                for (int j = 0; j < values[i]; j++) {
                    maxByColor[i + 1][j] = Math.max(maxByColor[i][j], color[i]);
                }
                for (int j = values[i]; j < 26; j++) {
                    maxByColor[i + 1][j] = maxByColor[i][j];
                }
            }
        }

        int max = 0;
        for (int i = 0; i < n; i++) max = Math.max(max, color[i]);
        out.println(max);

        out.print(color[0]);
        for (int i = 1; i < n; i++) {
            out.print(" ");
            out.print(color[i]);
        }
        out.println();
        out.close();
    }
}
