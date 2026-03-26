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
            Integer[] a = new Integer[n];
            StringTokenizer tokenizer = new StringTokenizer(br.readLine());
            for(int i = 0; i < n; i++){
                a[i] = Integer.parseInt(tokenizer.nextToken());
            }

            Arrays.sort(a);
            for(int i = n-1; i >= 0; i--){
                if( i < n-1) pw.print(" ");
                pw.print(a[i]);
            }
            pw.println();
        }

        pw.flush();
        pw.close();
        br.close();
    }
}