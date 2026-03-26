import java.util.*;

public class Hello {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        String str = sc.nextLine().trim();
        StringBuilder sb = new StringBuilder(str);
        for (char ch = 'z'; ch > 'a'; ch--) {
            for (int index = 0; index < sb.length(); index++) {
                if (sb.charAt(index) == ch) {
                    if ((index - 1 >= 0 && sb.charAt(index - 1) == ch - 1)
                            || (index + 1 < sb.length() && sb.charAt(index + 1) == ch - 1)) {
                        sb.deleteCharAt(index);
                        index = -1;
                    }
                }
            }
        }
        System.out.println(N - sb.length());
    }
}