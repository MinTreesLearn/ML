import java.util.Scanner;

public class DisplayTheNumbers {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int p = 0; p < t; p++){
            int n = in.nextInt();
            if ( n % 2 == 0){
                for ( int i = 0; i < n/2 - 1; i++){
                    System.out.print(1);
                }
                System.out.println(1);
            }
            else if ( n == 3){
                System.out.println(7);
            }
            else{
                System.out.print(7);
                    for (int i = 0; i < n / 2 - 2; i++) {
                        System.out.print(1);
                    }
                    System.out.println(1);
            }
        }
    }
}