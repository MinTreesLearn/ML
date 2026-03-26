import java.util.Scanner;
import java.util.Spliterator;

public class Book {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        while (n-- > 0) {
            int a = scan.nextInt(), b= scan.nextInt();
            int count = 0;
            if(a>b){
                if((a-b)%2==1) count =2;
                else count = 1;
            }
            else if(a<b){
                if((b-a)%2==1) count = 1;
                else count = 2;
            }
            else if(a==b) count = 0;
            System.out.println(count);
        }
    }
}