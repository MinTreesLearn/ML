import java.util.*;
import java.lang.*;
import java.io.*;
 public class main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t= sc.nextInt();
        while(t-->0){
        int n=sc.nextInt();
        String s =sc.next();
         char[] a = s.toCharArray();
         int ans=0;
        while(true){
             int c=0;
             for(int i=0;i<n-1;i++){
                 if(a[i]=='A'&& a[i+1]=='P'){
                     c++;
                     a[i+1]='A';
                     i++;
                 }
             }
                 if(c==0)
                 break;
                 else
                 ans++;
             }
        
     
    System.out.println(ans);    
        }
    
        
    }
}