import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t= in.nextInt();
        for(int T=1; T<=t; T++)
        {
            String s = in.next();
            int cnt=0,p1=0, p2=s.length()-1;
            while(p1<p2)
            {
                if(s.charAt(p1)=='0') p1++;
                 if(s.charAt(p2)=='0') p2--;
                 if(s.charAt(p1)=='1' && s.charAt(p2)=='1') break;
            }
            for(int i=p1; i<p2; i++)
            {
                if(s.charAt(i)=='0') cnt++;
            }
            if(s.length()==1)
            cnt=0;
            System.out.println(cnt);
        }
    }
}