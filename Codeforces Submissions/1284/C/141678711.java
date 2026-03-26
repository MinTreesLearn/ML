import java.util.Scanner;
 
public class H {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();
        long tab[] = new long[250006];
        long v =1;
        tab[0]=v;
        for (int i = 1; i <= a; i++) {
            v=(v*(i))%b;
            tab[i]=v;
        }
 
        long rs=0;
        long  m;
        long n;
        long tot;
 
        for (int i = 0; i < a; i++) {
            n=(long) Math.pow(a-i,2)%b;
            tot = (tab[a-i-1]*tab[i+1])%b;
            m = (long) (n*tot)%b;
            rs= (rs+ m)%b;
 
        }
        System.out.println(rs);
    }
}