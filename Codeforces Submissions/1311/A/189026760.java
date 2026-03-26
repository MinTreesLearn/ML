import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int test = input.nextInt();
        for( int i = 0; i < test; i++ ){
            int a = input.nextInt();
            int b = input.nextInt();

            if( a == b ) System.out.println("0");
            else{
                if( (a % 2 == 0 && b % 2 == 0) || ( a % 2 == 1 && b % 2 == 1 )){
                    if( a > b ) System.out.println("1");
                    else System.out.println("2");
                }
                else{
                    if( a > b ) System.out.println("2");
                    else System.out.println("1");
                }
            }
        }

        //input.close();
    }
}