import java.util.HashSet;
import java.util.Scanner;

public class practice_582 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-->0){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            a=Math.min(a,4);
            b=Math.min(b,4);
            c=Math.min(c,4);
            HashSet<String> s = new HashSet<>();
            while(a>0 || b>0 || c>0){
                if(a>0){
                    s.add("100");
                            a-=1;
                }
                if(b>0){
                    s.add("010");
                    b-=1;
                }
                if(c>0){
                    s.add("001");
                    c-=1;
                }


                if(a+b>=a+c) {
                    if (a > 0 && b > 0) {
                        s.add("110");
                        a -= 1;
                        b -= 1;
                    }
                }
                else {
                    if (a > 0 && c > 0) {
                        s.add("101");
                        a -= 1;
                        c -= 1;
                    }
                    if (a > 0 && b > 0) {
                        s.add("110");
                        a -= 1;
                        b -= 1;
                    }
                }
                if (a > 0 && c > 0) {
                    s.add("101");
                    a -= 1;
                    c -= 1;
                }
                if(b>0 && c>0){
                    s.add("011");
                    b-=1;
                    c-=1;
                }
                if(a>0 && b>0 && c>0){
                    s.add("111");
                }
            }
            boolean check=true;

            System.out.println(s.size());
        }
    }
}
