import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        ArrayList<Integer> arrayList = new ArrayList<>();
        int count = 0;
        int counter = 0;


        for (int i = 0; i < t; i++) {
            arrayList.add(sc.nextInt());
        }

        for (int i = 0; i < t * 2; i++) {
            if (arrayList.get(i % t) == 1) {
                counter++;
                count = Math.max(count, counter);
            } else {
                counter = 0;
            }

        }
        System.out.println(count);
    }
}