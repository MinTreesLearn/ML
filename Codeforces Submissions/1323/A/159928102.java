import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Task_5 {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        processWithoutDp(scanner);
//        processWithDp(scanner);
    }

    private static void processWithDp(Scanner scanner) {
        int t = getT(scanner);
        for (int i = 0; i < t; i++) {
            int elementsCount = Integer.parseInt(scanner.nextLine());
            int[] values = getValues(scanner);

            int sumElementsCount = 0;
            int[] dp = new int[elementsCount];
            if (values.length == 1) {
                sumElementsCount = values[0] % 2 == 0 ? 1 : -1;
            } else {
                dp[0] = (values[0] + values[1]) % 2 == 0 || values[0] % 2 == 0 ? values[0] : 0;
                sumElementsCount = dp[0] == 0 ? 0 : 1;
                for (int j = 1; j < dp.length; j++) {
                    int value = dp[j - 1] + values[j];
                    if (value % 2 == 0) {
                        dp[j] = value;
                        sumElementsCount++;
                    } else {
                        dp[j] = 0;
                    }
                }
            }

            System.out.println(sumElementsCount);
            if (sumElementsCount != -1) {
                int max = Arrays.stream(dp).max().orElse(0);
                int index = Arrays.stream(dp).mapToObj(n -> new Integer(n)).collect(Collectors.toList()).indexOf(max);
                Stream.iterate(index + 2 - sumElementsCount, n -> ++n)
                    .limit(sumElementsCount)
                    .forEach(n -> System.out.print(n.intValue() + " "));
                System.out.println();
            }
        }
    }

    private static void processWithoutDp(Scanner scanner) {
        int t = getT(scanner);

        for (int i = 0; i < t; i++) {
            scanner.nextLine();

            int[] values = getValues(scanner);

            int value = Arrays.stream(values).filter(n -> n % 2 == 0).findFirst().orElse(0);
            if (value != 0) {
                int index =
                    Arrays.stream(values).mapToObj(n -> new Integer(n)).collect(Collectors.toList()).indexOf(value);
                System.out.println(1);
                System.out.println(index + 1);
            } else {
                int index = 0;
                int sum = 0;
                for (int j = 0; j < values.length; j++) {
                    sum += values[j];
                    if (sum % 2 == 0) {
                        index = j;
                        break;
                    }
                }

                if (index == 0) {
                    System.out.println(-1);
                } else {
                    System.out.println(index + 1);
                    for (int d = 0; d < index + 1; d++) {
                        System.out.print(d + 1 + " ");
                    }
                }
            }
        }
    }

    private static int[] getValues(Scanner scanner) {
        return Arrays.stream(scanner.nextLine().split(" "))
            .mapToInt(Integer::parseInt)
            .toArray();
    }

    private static int getT(Scanner scanner) {
        return Integer.parseInt(scanner.nextLine());
    }
}
