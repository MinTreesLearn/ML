import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n,m;
        n = scanner.nextInt();
        m = scanner.nextInt();

        String [] str1 = new String[n];
        for (int i= 0;i< str1.length;i++){
            str1[i] = scanner.next();
        }

        String [] str2 = new String[m];
        for (int i= 0;i< str2.length;i++){
            str2[i] = scanner.next();

        }
        int t = scanner.nextInt();
        while (t-- > 0){

            int l = scanner.nextInt();
            String ans =str1[(l-1)%n] + str2[(l-1)%m];

            System.out.println(ans);


        }


    }
}