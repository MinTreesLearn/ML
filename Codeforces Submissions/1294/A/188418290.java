import java.util.Scanner;
import java.util.Spliterator;

public class Book {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        while (n-- > 0) {
            int a = scan.nextInt(), b = scan.nextInt(), c = scan.nextInt(), s = scan.nextInt();
            int v = Math.max(a,b);
            int d = Math.max(v,c);
            int m = s-((d-a)+(d-b)+(d-c));
            if(m>=0) System.out.println((m%3==0)?"YES":"NO");
            else System.out.println("NO");
        }
    }
}