import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class _1323A {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            int[] a = new int[n];
            List<Integer> indexes = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                a[j] = input.nextInt();
            }
            for (int j = 0; j < n; j++) {
                if (a[j] % 2 == 0) {
                    indexes.clear();
                    indexes.add(j + 1);
                    break;
                } else {
                    if (indexes.size() < 2) {
                        indexes.add(j + 1);
                    } else {
                        break;
                    }
                }
            }
            int count = indexes.size();
            if (count < 2 && a[indexes.get(count - 1) - 1] % 2 != 0) {
                System.out.println("-1");
            } else {
                StringBuilder answer = new StringBuilder();
                answer.append(String.format("%d%n", count));
                for (int j = 0; j < count - 1; j++) {
                    answer.append(String.format("%d ", indexes.get(j)));
                }
                answer.append(indexes.get(count - 1));
                System.out.println(answer);
            }
        }
    }

}