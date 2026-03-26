import java.util.Scanner;

public class Task1 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int repeats = scn.nextInt();
        for (int i = 0; i < repeats; i++) {
            int n = scn.nextInt(); //5
            int d = scn.nextInt();
            if(d<=n){
                System.out.println("YES");
                continue;
            }
            int x = 1;
            int c = func(x,d);
            int c1 = func(x+1,d);
            while (x<d && c >= c1 ) {
                x++;
                c = c1;
                c1 = func(x+1,d);
            }
            if (c <= n) {
                System.out.println("YES");
            }else {
                System.out.println("NO");
            }
        }
    }
    public static int func(int x, int d){
        return (int) (x + Math.ceil(d / (x + 1.0)));
    }
}