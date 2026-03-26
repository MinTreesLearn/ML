import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class test{
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            int n = Integer.parseInt(br.readLine());
            Integer[] a = new Integer[n*2];
            StringTokenizer tokenizer = new StringTokenizer(br.readLine());

            for(int i = 0; i < 2*n; i++){
                a[i] = Integer.parseInt(tokenizer.nextToken());
            }

            Arrays.sort(a);

            if(n % 2 == 0){
                // int min = Integer.MAX_VALUE;
                // for(int i = 2; i < (2*n) - 1; i++){
                //     min = Math.min(min, (int)(a[i] - a[i-1]));
                // }
                // pw.println(min);
                pw.println(a[n] - a[n-1]);
            }
            else{
                pw.println(a[n] - a[n-1]);
            }
        }

        pw.flush();
        pw.close();
        br.close();
    }
}