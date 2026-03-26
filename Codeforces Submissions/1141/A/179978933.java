import java.util.*;
import java.io.*;
import java.rmi.ConnectIOException;


  
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
        
       int n,m;

       FastReader f=new FastReader();

       n=f.nextInt();
       m=f.nextInt();
   
        int cnt=0;
        
        if(m%n!=0){
            System.out.println(-1);
            return;
        }


        int d=m/n;

        while(d%2==0){
            d/=2;
            cnt++;
        }

        while(d%3==0){
            d/=3;
            cnt++;
        }

        if(d==1)
        System.out.println(cnt);
        else
        System.out.println(-1);
        


      }
}
