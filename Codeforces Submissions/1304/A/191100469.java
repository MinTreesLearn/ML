import java.util.*;

public class hopping{
    public static void main (String[] args){
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while(t-- > 0){
            long x = scan.nextLong();
            long y = scan.nextLong();
            long a = scan.nextLong();
            long b = scan.nextLong();
            long i = y-x;
            long j = a+b;
            System.out.println(i%j > 0 ? -1 : i/j);
        } 
    }
}