import java.util.Scanner;

public class DeadPixel_1315A {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while(t-->0){
            int a = s.nextInt();
            int b = s.nextInt();
            int x = s.nextInt();
            int y = s.nextInt();
            int horizontal = Math.max(x,a-1-x);
            int vertical = Math.max(y,b-1-y);
            int a1 = horizontal*b;
            int a2 = vertical*a;
            System.out.println(Math.max(a1,a2));
        }
    }
}