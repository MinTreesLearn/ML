import java.util.*;
import java.io.*;

public class yetAnotherTetrisProblem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // try {
        //     scanner = new Scanner(new FileInputStream("input.txt"));
        // }
        // catch (Exception e) {
        //     System.out.println("Error");
        // }

        int t = scanner.nextInt();

        for (int x = 0; x < t; x++) {
            int n = scanner.nextInt();
            int odds = 0;
            for (int i = 0; i < n; i++) {
                if (scanner.nextInt() % 2 != 1) {
                    odds++;
                }
            }
            if (odds == n || odds == 0) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }



        }
    }


}
