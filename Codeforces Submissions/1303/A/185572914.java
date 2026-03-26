import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            int a = 0, b = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '1') {
                    a = i;
                    break;
                }
            }
            for (int i = s.length() - 1; i > 0; i--) {
                if (s.charAt(i) == '1') {
                    b = i;
                    break;
                }
            }
            int count = 0;
            for (int i = a; i < b; i++) {
                if (s.charAt(i) == '0') {
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}
