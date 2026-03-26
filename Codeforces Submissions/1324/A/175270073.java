import java.util.*;
public class code {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int even = 0;
            int n = sc.nextInt();
            for(int i = 0;i<n;i++){
                int a = sc.nextInt();
                if(a % 2 == 0){
                    even ++;
                }
            }
            System.out.println((even == 0 || even == n)?"YES":"NO");
        }
    }
}