// A Java program to convert an ArrayList to arr[]
import java.util.Scanner;
public class code{
    public static long count_3(long n , int t){
        long count_t = 0;
        while(n>0 && n%t==0){
            count_t+=1;
            n = n/t;
        }
        return count_t;
    }
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
       long n = s.nextLong();
       long m = s.nextLong();
       if(m%n!=0){
           System.out.println(-1);
       }else{
           // division is possible so 
           long ans1 = m/n;
           // now this number ans1 should have only two prime factor one 3 or 2 
          long k = ans1;
           int count = 0;
           while(k%2==0 && k>0){
               k = k/2;
               count+=1;
           }
           while(k%3==0 && k>0){
               k  = k/3;
               count+=1;
           }
           if(k==1){
               System.out.println(count);
           }else{
               System.out.println(-1);
           }
       }
       
    }
}