import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


public class Main {
    static int n, m;
    static ArrayList<Integer>[] adj;
    static boolean [] visited;
    public static void main (String [] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
     int t = Integer.parseInt(br.readLine());
       for (int i=0; i<t; i++) {
           int n = Integer.parseInt(br.readLine());
           int x = 1, y = 1, z = 1;
           for (int a=2; a<=Math.sqrt(n); a++) {
               if (n % a == 0) {
                   int k = n / a;
                   for (int b=2; b<=Math.sqrt(k); b++) {
                       if (k % b == 0 && a!=k/b && a!=b && b!=k/b && k > b) {
                           x = a;
                           y = b;
                           z = k / b;
                       }
                   }
               }
           }
           if (x==1 && y==1 && z==1) {
               System.out.println("NO");
           }
           else {
               System.out.println("YES");
               System.out.println(x + " " + y  + " " + z);
           }

       }
     
    }


}
