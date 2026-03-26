import java.io.*;
import java.util.*;
public class Bogosort
{
   public static void main(String[] args) throws IOException
   {
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      for (int q = Integer.parseInt(in.readLine()); q > 0; --q) {
         int n = Integer.parseInt(in.readLine());
         int[] a = new int[n];
         StringTokenizer st = new StringTokenizer(in.readLine());
         for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
         }
         Arrays.sort(a);
         for (int i = n; --i >= 0;) {
            System.out.print(a[i] + " ");
         }
         System.out.println();
      }
   }
}