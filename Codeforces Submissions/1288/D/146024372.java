import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        //BufferedReader f = new BufferedReader(new FileReader("uva.in"));
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] a = new int[n][m];
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(f.readLine());
            for(int j = 0; j < m; j++) {
                a[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int L = 1 << m;
        int low = 0;
        int high = 1000000000;
        int x = 0;
        int y = 0;
        while(low <= high) {
            int mid = (low+high)/2;
            int[] idx = new int[L];
            for(int i = 0; i < n; i++) {
                int temp = 0;
                for(int j = 0; j < m; j++) {
                    temp <<= 1;
                    if(a[i][j] >= mid) {
                        temp |= 1;
                    }
                }
                idx[temp] = i+1;
            }
            boolean flag = false;
            for(int i = 0; i < L; i++) {
                for(int j = 0; j < L; j++) {
                    if(idx[i] > 0 && idx[j] > 0 && (i|j) == L-1) {
                        flag = true;
                        x = idx[i];
                        y = idx[j];
                        break;
                    }
                }
                if(flag) {
                    break;
                }
            }
            if(flag) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        out.println(x + " " + y);
        f.close();
        out.close();
    }
}
