import java.util.Scanner;

public class App {
    private static Scanner fs;

    public static void solve() {
        int a=fs.nextInt();
        int b=fs.nextInt();
        int x=fs.nextInt();
        int y=fs.nextInt();

        int ans=0;
        ans=Math.max(x*b,(a-x-1)*b);
        ans=Math.max(ans,Math.max(y*a,(b-y-1)*a));

        System.out.println(ans); 
    }

    public static void main(String[] args) {
        fs = new Scanner(System.in);
        int t=fs.nextInt();

        while (t>0) {
            solve();
            t--;
        }

        fs.close();
    }
}
