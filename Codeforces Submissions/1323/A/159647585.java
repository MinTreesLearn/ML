import java.io.FileNotFoundException;
import java.util.Scanner;

public class Task5 {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        for (int k = 0; k < t; k++) {
            int n = scn.nextInt();
            boolean[] dp = new boolean[n];
            boolean found = false;
            for (int i = 0; i < n; i++) {
                if(found){
                    scn.nextInt();
                    continue;
                }
                boolean isEven = scn.nextInt() % 2 == 0;
                dp[i] = isEven;
                if (isEven) {
                    System.out.println(1);
                    System.out.println(i+1);
                    found = true;
                } else if (i != 0 && !dp[i - 1]) {
                    System.out.println(2);
                    System.out.println(i + " " + (i+1));
                    found=true;
                }
            }
            if (!found) {
                System.out.println(-1);
            }
        }
    }
}