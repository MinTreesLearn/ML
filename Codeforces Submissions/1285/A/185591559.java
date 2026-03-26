import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int count1 = 0, count2 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'L') {
                count1--;
            } else {
                count2++;
            }
        }
        System.out.println(count2 - count1 + 1);
    }
}
