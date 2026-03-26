import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class StringColoring {
    int[] tree;

    private void insert(int num, int index, int a, int b, int node) {
        if (a == b) {
            tree[node] = num;
            return;
        }

        int mid = (a +b ) / 2;
        if (index <= mid) {
            insert(num, index, a, mid, node * 2);
        } else {
            insert(num, index, mid + 1, b, node * 2 + 1);
        }

        tree[node] = Math.max(tree[node * 2], tree[node * 2 + 1]);
    }

    private int get(int from, int to, int a, int b, int node) {
        if (from <= a && b <= to) {
            return tree[node];
        }

        int mid = (a + b) / 2;
        int max = 0;
        if (from <= mid) {
            max = Math.max(max, get(from, to, a, mid, node * 2));
        }
        if (to > mid) {
            max = Math.max(max, get(from, to, mid + 1, b, node * 2 + 1));
        }

        return max;
    }

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
        tree = new int[26 * 4 + 5];
        for (int i = 0; i < n; i++) {
            if (values[i] == 25) {
                color[i] = 1;
            } else {
                color[i] = get(values[i] + 1, 25, 0, 25, 1) + 1;
            }
            insert(color[i], values[i], 0, 25, 1);

            /*
            System.out.println(values[i] + " " + get(values[i], values[i], 0, 25, 1));
            for (int j = 0; j < 26; j++) {
                System.out.print(get(j, j, 0, 25, 1) + " ");
            }
            System.out.println(); */
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
