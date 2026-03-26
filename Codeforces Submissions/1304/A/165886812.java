import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(), x, y, a, b;
        double c;
        while(t -- > 0){
            x = sc.nextInt();
            y = sc.nextInt();
            a = sc.nextInt();
            b = sc.nextInt();
            c = 1.0 * (y - x) / (a + b);
            System.out.println(c == (int)c ? (int)c : -1);
        }
        sc.close();
    }
}