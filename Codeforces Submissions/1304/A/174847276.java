import java.util.Scanner;

public class MyClass {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0)
        {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            if((int)Math.ceil((double)(y-x)/(double)(a+b)) == ((y-x)/(a+b)))
                System.out.println((y-x)/(a+b));
            else System.out.println("-1");
            t--;
        }
    }
}