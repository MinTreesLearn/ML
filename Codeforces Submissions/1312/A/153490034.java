import java.util.Scanner;

public class CodeForce {

    public static void main(String[] args) {

      Scanner in = new Scanner(System.in);

      int testCases = in.nextInt();
      in.nextLine();
      int a, b;

      for(int t = 1; t <= testCases; t ++) {

        a = in.nextInt();
        b = in.nextInt();
        in.nextLine();

        if(a % b == 0) {
          System.out.println("YES");
        } else {
          System.out.println("NO");
        }

      }

    }

}
