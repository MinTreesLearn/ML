import java.util.*;
public class ThreeStrings {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        sc.nextLine();
        for(int i=0;i<t;i++)
        {
            int count=0;
          String a=sc.nextLine();
            String b=sc.nextLine();
            String c=sc.nextLine();
            /*if(a.equals(b))
            {
                System.out.println("YES");
                continue;
            }*/
            for(int j=0;j<a.length();j++)
            {
                char ch1=a.charAt(j);
                char ch2=c.charAt(j);
                char ch3=b.charAt(j);
                if(ch1==ch2)
                {
                   b= swap(b,c,j);
                   count++;
            }
            else if(ch3==ch2)
        {
            a=swap(a,c,j);
            count++;
        }
            else
                    continue;
        }
            if(a.equals(b)&&count==a.length())
                System.out.println("YES");
            else
                System.out.println("NO");
    }
}
    private static String swap(String s1, String s2, int idx) {
        char ch1=s2.charAt(idx);
        char ch2=s1.charAt(idx);
        s1=s1.substring(0,idx)+ch1+s1.substring(idx+1);
        s2=s2.substring(0,idx)+ch2+s2.substring(idx+1);
        return s1;
    }
    }
