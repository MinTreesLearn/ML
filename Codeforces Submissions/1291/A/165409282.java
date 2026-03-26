import java.util.*;
public class MyClass {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int k=sc.nextInt();
        while(k-->0){
            int n=sc.nextInt();
            String str=sc.next();
           int odd=0;
           for(int i=0;i<str.length();i++){
               if((str.charAt(i)-'0')%2!=0) odd++;
           }
           if(odd<=1) System.out.println("-1");
           else{
           StringBuilder sb=new StringBuilder();
           for(int i=0;i<str.length();i++){
               if((str.charAt(i)-'0')%2!=0) sb.append(str.charAt(i));
               if(sb.length()==2) break;
           }
            System.out.println(sb.toString());
           }
        }
    }

   
}