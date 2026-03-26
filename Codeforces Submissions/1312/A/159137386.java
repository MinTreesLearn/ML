import java.util.*;
import java.lang.*;
public class cf {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int l= sc.nextInt(), r=sc.nextInt();
            if (l%r == 0) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
        }
    }
}