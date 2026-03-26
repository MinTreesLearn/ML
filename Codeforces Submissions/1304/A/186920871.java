import java.util.*;

public class CP {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int testcases = sc.nextInt();
        while(testcases-->0){
            long x = sc.nextLong();
            long y = sc.nextLong();
            long a = sc.nextLong();
            long b = sc.nextLong();
            long v = Math.abs(x-y);
            long z = Math.abs(a+b);
            if(v%z==0){
                System.out.println(v/z);
            }
            else{
                System.out.println("-1");
            }
        }
    }


}