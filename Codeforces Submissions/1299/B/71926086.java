import java.util.*;
import java.io.*;
public class B618
{
    public static void main(String [] args)
    {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        int [][] points = new int [n+1][2];
        for (int i = 1; i <= n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            points[i][0] = a;
            points[i][1] = b;
        }
        if (n % 2 == 1) {
            out.println("NO");
        } else {
            int mid_x = (points[n/2][0] + points[n][0]); int mid_y = (points[n/2][1] + points[n][1]);
            boolean good = true;
            for (int i = 1; i < n / 2; i++) {
                int x = (points[i][0] + points[i+n/2][0]);
                int y = (points[i][1] + points[i + n/2][1]);
                if (x == mid_x && y == mid_y) {
                    continue;
                } else {
                    good = false;
                    break;
                }
            }
            if (good) out.println("YES"); else out.println("NO");
        }

        out.close();
    }


    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }



    }

}