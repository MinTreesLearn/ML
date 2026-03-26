import java.util.*;

public class SolveJava{
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        
        int ts = in.nextInt();
        while(ts-- > 0){
            int a = in.nextInt(), b, x = 0, y = 0;
            b = in.nextInt();
            if(a % 2 == 1) x = 1;
            if(b % 2 == 1) y = 1;
            if(a == b) System.out.println(0);
            else if(x == 1 && y == 1 && a > b) System.out.println(1);
            else if(x == 0 && y == 1 && b > a) System.out.println(1);
            else if(x == 1 && y == 0 && b > a) System.out.println(1);
            else if(x == 0 && y == 0 && a > b) System.out.println(1);
            else if(x == 1 && y == 0 && a > b) System.out.println(2);
            else if(x == 1 && y == 1 && b > a) System.out.println(2);
            else if(x == 0 && y == 1 && a > b) System.out.println(2);
            else System.out.println(2);
        }
    }
}