import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        //BufferedReader f = new BufferedReader(new FileReader("uva.in"));
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int t = Integer.parseInt(f.readLine());
        while(t-- > 0) {
            StringTokenizer st = new StringTokenizer(f.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int ans = 30000;
            int resA = 0;
            int resB = 0;
            int resC = 0;
            for(int A = 1; A <= 10000; A++) {
                for(int B = A; B <= 20000; B += A) {
                    int C1 = c/B*B;
                    int C2 = (c+B-1)/B*B;
                    int temp = Math.abs(A-a)+Math.abs(B-b)+Math.abs(C2-c);
                    if(temp < ans) {
                        ans = temp;
                        resA = A;
                        resB = B;
                        resC = C2;
                    }
                    if(C1 > 0) {
                        temp = Math.abs(A-a)+Math.abs(B-b)+Math.abs(C1-c);
                        if(temp < ans) {
                            ans = temp;
                            resA = A;
                            resB = B;
                            resC = C1;
                        }
                    }
                }
            }
            out.println(ans);
            out.println(resA + " " + resB + " " + resC);
        }
        f.close();
        out.close();
    }
}
