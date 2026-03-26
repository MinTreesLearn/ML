import java.util.Scanner;

public class Main {
    static long cnt = 0;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            String s = sc.next();
            int cnt = 0;
            String ans = " ";
            for (int i = 0; i < n; i++) {
                char c = s.charAt(i);
                if ((c - '0') % 2 == 1) {
                    ans += c; 
                    cnt++;
                }
                if (cnt == 2) {
                    System.out.println(ans);
                    break;
                }
            }

            if (cnt != 2) {
                System.out.println(-1);
            }
        }
    }

}
