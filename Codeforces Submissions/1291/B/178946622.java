import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Problem1676H1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long t = scanner.nextInt();
        while(t-- > 0){
            long n = scanner.nextLong();
            List<Long> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(scanner.nextLong());
            }
            int preff = -1;
            int suff = list.size();
            for (int i = 0; i < list.size(); i++) {
                if (list.get(i) < i)
                    break;
                preff = i;
            }
            for (int i = list.size() - 1; i >= 0; i--) {
                if (list.get(i) < list.size() - 1 - i)
                    break;
                suff = i;
            }
            if (preff >= suff)
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }
}
