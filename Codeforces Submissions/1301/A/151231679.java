import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        in.nextLine();
        for(int c=0;c<t;c++)
        {
            String a=in.nextLine();
            String b=in.nextLine();
            String s=in.nextLine();
            boolean result=true;
            for(int i=0;i<a.length();i++)
            {
                if(!(a.charAt(i)==s.charAt(i)||b.charAt(i)==s.charAt(i)))
                {
                    result=false;
                    break;
                }
            }
            if(result)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}