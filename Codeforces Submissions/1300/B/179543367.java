import java.util.*;
import java.io.*;


  
  public class Problem{
      static class FastReader {
      BufferedReader br;
      StringTokenizer st;

      public FastReader()
      {
          br = new BufferedReader(
              new InputStreamReader(System.in));
      }

      String next()
      {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              }
              catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }

      int nextInt() { return Integer.parseInt(next()); }

      long nextLong() { return Long.parseLong(next()); }

      double nextDouble()
      {
          return Double.parseDouble(next());
      }

      String nextLine()
      {
          String str = "";
          try {
              if(st.hasMoreTokens()){
                  str = st.nextToken("\n");
              }
              else{
                  str = br.readLine();
              }
          }
          catch (IOException e) {
              e.printStackTrace();
          }
          return str;
      }
  }
  
      public static void main(String[] args){
        
        int t;
        FastReader f=new FastReader();
            t=f.nextInt();

        while(t-->0){
            int n;
            n=f.nextInt();
            int[] arr=new int[2*n];

            for (int i = 0; i < arr.length; i++) {
                arr[i]=f.nextInt();
            }

            Arrays.sort(arr);

            System.out.println(arr[arr.length/2]-arr[arr.length/2-1]);

        }
         
        
      }
}
