import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0){
            long n = sc.nextInt();long d = sc.nextInt();
            if(d<=n){
                System.out.println("YES");
            }else{
                if((n-1)*(n-1) - 4*(d-n) >=0){
                    System.out.println("YES");
                }else{
                    System.out.println("NO");
                }
            }
            t--;
        }
    }
}
