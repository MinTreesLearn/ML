import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        //Scanner sc = new Scanner(new File(".in"));

        int n = sc.nextInt();


        for (int i = 0; i < n; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int ans = 0;

            if (a == b) {
                ans = 0;
            }else if (a - b < 0){
                if ((b - a) % 2 == 1){
                    ans++;
                }else{
                    ans = ans + 2;
                }
            }else {
                if ((a - b) % 2 == 0){
                    ans++;
                }else {
                    ans = ans + 2;
                }
            }

            System.out.println(ans);

        PrintWriter out = new PrintWriter(".out");
        out.println();
        out.close();
    }

}}