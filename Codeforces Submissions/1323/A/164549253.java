import java.io.*;
import java.util.*;
 
public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        
        while(t-->0){
            int n = Integer.parseInt(br.readLine().trim());
            String[] in = br.readLine().trim().split(" ");
            if(n==1){
                int num = Integer.parseInt(in[0]);
                if((num & 1) != 0){
                    System.out.println(-1);
                }else{
                    System.out.println(n+"\n"+1);
                }
            }else{
                int num1 = Integer.parseInt(in[0]);
                int num2 = Integer.parseInt(in[1]);
                
                if((num1 & 1) == 0){
                    System.out.println(1);
                    System.out.println(1);
                }else if((num2 & 1) == 0){
                    System.out.println(1);
                    System.out.println(2);
                }else{
                    System.out.println(2);
                    System.out.println(1+" "+2);
                }
            }
        }
    }
}