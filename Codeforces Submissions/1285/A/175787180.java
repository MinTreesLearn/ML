import java.util.*;

public class java {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        String g = scan.next();
        int c = 0, q = 0;
        for (int i = 0; i < x; i++) {
            if(g.charAt(i)=='R'){
                c++;
            }
            else{
                q++;
            }
        }
        System.out.println(c+q+1);
    }
}