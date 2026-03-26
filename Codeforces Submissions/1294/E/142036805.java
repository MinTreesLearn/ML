import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        //BufferedReader f = new BufferedReader(new FileReader("uva.in"));
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowjump.out")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] a = new int[n][m];
        int[] row = new int[n*m+1];
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(f.readLine());
            for(int j = 0; j < m; j++) {
                a[i][j] = Integer.parseInt(st.nextToken());
                row[i*m+j+1] = i;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int[] diff = new int[n+1];
            for(int j = 0; j < n; j++) {
                if(a[j][i] < 1 || a[j][i] > n*m || a[j][i]%m != (i+1)%m) {
                    diff[n]++;
                } else {
                    diff[(j-row[a[j][i]]+n)%n]++;
                }
            }
            int min = n;
            for(int j = 0; j < n; j++) {
                min = Math.min(min, n-diff[j]+j);
            }
            ans += min;
        }
        out.println(ans);
        f.close();
        out.close();
    }
}
