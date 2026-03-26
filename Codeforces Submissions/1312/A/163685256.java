import java.util.Scanner;

public class Main{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(), n, m;
        while(t -- > 0){
            n = sc.nextInt();
            m = sc.nextInt();
            System.out.println(n % m == 0 || m % n == 0 ? "YES" : "NO");
        }
        sc.close();
    }
}