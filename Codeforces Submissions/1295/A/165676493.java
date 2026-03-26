import java.util.*;
import java.io.*;
public class coins {
  
  public  static void  main(String...args)throws IOException{
    // Scanner sc=new Scanner(System.in);
    // BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      InputStreamReader r=new InputStreamReader(System.in);    
    BufferedReader br=new BufferedReader(r);  
        int t=Integer.parseInt(br.readLine());
       while(t-->0){
        int n=Integer.parseInt(br.readLine());
        int k=0;
        String str="";
        int nine =0,seven=0,ct=0;
        ct=n/2;
        if(n%2!=0){
          ct--;
          str=str+'7';
        }
         while(ct-->0){
   str+='1';
        }
         System.out.println(str);
       }
  }
}