import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();

        int[][] count = new int[s.length() + 1][26];

        for (int i = 0; i < s.length(); ++i) {
            count[i + 1] = count[i].clone();
            count[i + 1][s.charAt(i) - 'a'] += 1;
        }

        int q = input.nextInt();
        while (q-- != 0) {
            int l = input.nextInt() - 1, r = input.nextInt() - 1;
            int distinct = 0;
            for (int i = 0; i < 26; ++i) {
                distinct += (count[r + 1][i] != count[l][i] ? 1 : 0);
            }
            if (l != r && s.charAt(l) == s.charAt(r) && distinct < 3) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
            }
        }
    }
}
