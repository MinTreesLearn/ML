import java.util.Scanner;

public class MaximalContinuousRest {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        int count = 1;
        int max = 1;
        int count1 = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
            if (arr[i] == 1) {
                count1++;
            }
        }
        if (count1 == 0) {
            System.out.println(0);
        } else {
            for (int i = 1; i < n; i++) {
                if (arr[i - 1] == 1 && arr[i] == 1) {
                    count++;
                } else {
                    max = Math.max(max, count);
                    count = 1;
                }
            }
            if (arr[n - 1] == 1) {
                for (int i = 0; i < n; i++) {
                    if (arr[i] == 1) {
                        count++;
                    } else {
                        break;
                    }
                }
                System.out.println(Math.max(count, max));
            } else {
                System.out.println(max);
            }
        }
    }
}