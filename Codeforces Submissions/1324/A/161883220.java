import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            ArrayList<Integer> arrayList = new ArrayList<>();
            int sum = 0;

            for (int j = 0; j < n; j++) {
                arrayList.add(sc.nextInt() % 2);
                sum += arrayList.get(j);
            }

            if (sum == arrayList.size() || sum == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }

        }

    }
}
