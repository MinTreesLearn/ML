import java.util.Scanner;

public class JoeIsOnTV {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double n = in.nextDouble();
        double ans = 0;
        while ( n > 0){
            ans += 1/n;
            n--;
        }
        System.out.println(ans);
    }
}