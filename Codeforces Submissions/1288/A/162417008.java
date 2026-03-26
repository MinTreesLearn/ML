import java.util.Arrays;
import java.util.Scanner;

public class Task1 {

    public static void main(String[] args) {
        process(new Scanner(System.in));
    }

    private static void process(Scanner scanner) {
        int count = getValue(scanner);
        for (int z = 0; z < count; z++) {
            int[] values = getValues(scanner);
            int n = values[0];
            int d = values[1];

            int left = 0;
            int right = n;
            int middle = left + (right - left) / 2;
            while (left < right - 1) {
                middle = left + (right - left) / 2;
                int currentN = middle + (int)Math.ceil(d * 1.0 / (middle + 1));
                if (currentN == n)
                    break;

                if (currentN < n) {
                    left = middle;
                } else {
                    right = middle;
                }
            }

            middle = left + (right - left) / 2;
            System.out.println(n == middle + (int)Math.ceil(d * 1.0 / (middle + 1)) || n == d ? "YES" : "NO");
        }
    }

    private static int getValue(Scanner scanner) {
        return Integer.parseInt(scanner.nextLine());
    }

    private static int[] getValues(Scanner scanner) {
        return Arrays.stream(scanner.nextLine().split(" "))
            .mapToInt(Integer::parseInt)
            .toArray();
    }
}
