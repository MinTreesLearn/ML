
import java.util.Scanner;

/**
 * @author 明宇
 * @version 1.0
 */
public class MainT7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int s = n;
            while (n >= 10) {
                s += n / 10;
                n = (n / 10) + (n % 10);
            }
            System.out.println(s);
        }
    }
}
	 	 	   		     			  	 			 	 		