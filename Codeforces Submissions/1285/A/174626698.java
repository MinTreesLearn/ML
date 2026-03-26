import java.util.Scanner;

public class testing11 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        char[] ch = in.nextLine().toCharArray();
        int l = 0, r = 0;
        for(char c : ch) {
            if(c=='L') l++;
            else r++;
        }
        System.out.println(1 + r + l);
    }
}
