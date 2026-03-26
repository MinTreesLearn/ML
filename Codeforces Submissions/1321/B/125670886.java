import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static final Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    public static Map<Long, Long> mp = new HashMap<>();

    public static void main(String[] args) {

        int n = scanner.nextInt();

        if (n <= 0) {
            System.out.println(0);
            return;
        } else if (n == 1) {
            long x = scanner.nextLong();
            System.out.println(x);
            return;
        }

        for (int i = 1; i <= n; i++) {
            long x = scanner.nextLong();
            mp.put(x - i, mp.getOrDefault(x - i, 0L) + x);
        }

        long mv = 0;
        for (long p : mp.keySet()) {
            mv = Math.max(mv, mp.get(p));
        }

        System.out.println(mv);

    }

}
