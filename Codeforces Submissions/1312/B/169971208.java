import java.util.*;
import java.io.*;
public class BogoSort{
   public static void main(String [] args) throws Exception{
      BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
      int a = Integer.parseInt(input.readLine());
      while(a-->0){
         int b = Integer.parseInt(input.readLine());
         int [] c = Arrays.stream(input.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
         Arrays.sort(c);
         String ans="";
			for(int i=b-1;i>=0;i--) ans+=c[i]+" ";
			System.out.println(ans);
      }    
   }
}