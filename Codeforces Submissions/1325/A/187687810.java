/*package whatever //do not write package name her*/
import java.util.Scanner;
public class code{
    public static void main(String args[]){
        Scanner s  = new Scanner(System.in);
        int T = s.nextInt();
        while(T-->0){
            int x = s.nextInt();
            int a = x/2;
            int b = x/2;
            if(x%2!=0){
                a = 1;
                b = x-1;
            }
            System.out.println(a+" "+b);
        }
    }
}