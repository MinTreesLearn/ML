import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for(int i = 0; i < t; i++)
        {
            int a = input.nextInt();
            int b = input.nextInt();
            if(a < b)
            {
                if((b - a) % 2 == 0){
                    System.out.println(2);
                }
                else{
                    System.out.println(1);
                }
            }
            else if(a > b)
            {
                if((a - b) % 2 == 0){
                    System.out.println(1);
                }
                else{
                    System.out.println(2);
                }
            }
            else
            {
                System.out.println(0);
            }
        }
    }
}
